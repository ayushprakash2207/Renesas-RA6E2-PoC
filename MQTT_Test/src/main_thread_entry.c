#include "main_thread.h"
#include "common_utils.h"
#include "mpu_wrappers.h"
#include "timers.h"

#define CONNECT_TIMEOUT     (1000)
#define WIDTH_64            (64)

float ecg_temp = 21.34f;
char adc_json[200];

mqtt_onchip_da16xxx_instance_ctrl_t g_rm_mqtt_onchip_da16xxx_instance;

float generate_random_float(float min, float max);
void generate_adc_ecg_data(char *buffer, size_t buffer_size);
void vTimerCallback(TimerHandle_t pxTimer );




mqtt_onchip_da16xxx_pub_info_t pubTopics[2] =
{
    {
        .qos                 = MQTT_ONCHIP_DA16XXX_QOS_0,
        .p_topic_name        = CLIENT_PUB_TOPIC,
        .topic_name_Length   = sizeof(CLIENT_PUB_TOPIC)
    },
    {
            .qos                 = MQTT_ONCHIP_DA16XXX_QOS_0,
            .p_topic_name        = CLIENT_PUB_TOPIC1,
            .topic_name_Length   = sizeof(CLIENT_PUB_TOPIC1)
    }
};

/* Setup Access Point connection parameters */
WIFINetworkParams_t net_params =
{
    .ucChannel                  = 0,
    .xPassword.xWPA.cPassphrase = WIFI_PWD,
    .ucSSID                     = WIFI_SSID,
    .xPassword.xWPA.ucLength    = sizeof(WIFI_PWD),
    .ucSSIDLength               = sizeof(WIFI_SSID),
    .xSecurity                  = eWiFiSecurityWPA2,
};

/* Main Thread entry function */
/* pvParameters contains TaskHandle_t */
void main_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    WIFIReturnCode_t wifi_err;
    WIFIIPConfiguration_t ipconfig;

    /* Open connection to the Wifi Module */
    wifi_err = WIFI_On();
    if (eWiFiSuccess != wifi_err)
    {
        APP_PRINT("\r\n Wi-Fi initialization failed! \r\n");
    }

    APP_PRINT("\r\nConnecting to Wi-Fi.. \r\n");

    /* Connect to the Access Point */
    wifi_err = WIFI_ConnectAP(&net_params);
    if (eWiFiSuccess != wifi_err)
    {
        APP_PRINT("\r\n Wi-Fi connection failed! \r\n");
    }

    APP_PRINT("\r\n Wi-Fi connection successful! \r\n");

    if (WIFI_GetIPInfo(&ipconfig) != eWiFiSuccess)
    {
        APP_PRINT("\r\n Failed to get IP info \r\n");
    }

    APP_PRINT("\r\nIP Addr: %d.%d.%d.%d\r\n",
        ((uint8_t *)ipconfig.xIPAddress.ulAddress)[0],
        ((uint8_t *)ipconfig.xIPAddress.ulAddress)[1],
        ((uint8_t *)ipconfig.xIPAddress.ulAddress)[2],
        ((uint8_t *)ipconfig.xIPAddress.ulAddress)[3]);

    fsp_err_t mqtt_err;

    APP_PRINT("\r\nConnecting to secure AWS IoT...\r\n");
    mqtt_err = RM_MQTT_DA16XXX_Open(&g_rm_mqtt_onchip_da16xxx_instance, &g_mqtt_onchip_da16xxx_cfg);
    if (FSP_SUCCESS != mqtt_err)
    {
        APP_PRINT("\r\nMQTT initialization failed!\r\n");
    }
    else
    {
        APP_PRINT("\r\nMQTT initialization Success!\r\n");
    }

    APP_PRINT("\r\nConnecting to AWS mqtt broker!\r\n");
    /* Connect to the MQTT Broker */
    for (int i = 0; i < 5; i++)
    {
        mqtt_err = RM_MQTT_DA16XXX_Connect(&g_rm_mqtt_onchip_da16xxx_instance, CONNECT_TIMEOUT);
        if (FSP_SUCCESS == mqtt_err)
        {
            APP_PRINT("\r\nConnection successful!\r\n");
            break;
        }
        else if (i > 3)
        {
            APP_PRINT("\r\nMQTT connection failed!\r\n");
        }
        else
        {
            APP_PRINT("%s\r\n", mqtt_err);
        }
    }

    /* TODO: add your own code here */
    while (1)
    {

        /* Assign payload pointer to sensor data buffer */
        pubTopics[0].p_payload = adc_json;

        generate_adc_ecg_data(adc_json, 200);

        pubTopics[0].payload_length = strlen(pubTopics[0].p_payload);

        mqtt_err = RM_MQTT_DA16XXX_Publish(&g_rm_mqtt_onchip_da16xxx_instance, &pubTopics[0]);
        if (FSP_SUCCESS != mqtt_err)
        {
            APP_PRINT("\r\nMQTT publish failed, %d\r\n", mqtt_err);
            break;
        }

        vTaskDelay (pdMS_TO_TICKS(100));
    }
}

float generate_random_float(float min, float max)
{
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

void mqtt0_callback(mqtt_onchip_da16xxx_callback_args_t * p_args)
{
    (void)p_args;
}


/*
 * Dummy ECG Data Generation
 */

#define PI 3.14159265359
#define ECG_SAMPLES 50    // Number of samples in one cycle
#define SAMPLE_RATE 1000  // 1000 Hz sample rate (1 ms per sample)
#define ADC_MAX 4095      // 12-bit ADC maximum value

// Function to generate synthetic ECG ADC data
void generate_adc_ecg_data(char *buffer, size_t buffer_size) {
    static int sample_index = 0;
    double frequency = 1.0;  // 1 Hz (heartbeat frequency)
    double amplitude = 1.0;  // Normalized amplitude
    double noise_level = 0.02;  // Noise factor

    // ECG waveform simulation (sum of sine waves)
    double time = (double)sample_index / SAMPLE_RATE;
    double ecg_signal = amplitude * (sin(2 * PI * frequency * time) +
                                     0.2 * sin(4 * PI * frequency * time) +
                                     0.1 * sin(6 * PI * frequency * time));

    // Add noise
    ecg_signal += noise_level * ((rand() % 100) / 100.0 - 0.5);

    // Scale to ADC range (assuming mid-range voltage is ~2048)
    int adc_value = (int)((ecg_signal + 1.0) * (ADC_MAX / 2.0));
    if (adc_value < 0) adc_value = 0;
    if (adc_value > ADC_MAX) adc_value = ADC_MAX;

    sample_index = (sample_index + 1) % ECG_SAMPLES;

    snprintf(buffer, buffer_size, "%d", adc_value);
}
