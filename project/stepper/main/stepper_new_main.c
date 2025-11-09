#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h" // GPIO kontrolü için gerekli başlık
#include "esp_log.h"
#include "rom/ets_sys.h" // ets_delay_us için

// DRV8825 Bağlantıları (ESP8266 Dahili GPIO Numaraları)
#define MOTOR_STEP_PIN  GPIO_NUM_2  // D4 pini
#define MOTOR_DIR_PIN   GPIO_NUM_0  // D3 pini

#define STEPS_PER_REVOLUTION 1000 // Motorun tam bir dönüşü için gereken adım sayısı

// Yön Tanımlamaları
#define YUKARI_YON      1           // Açılma yönü
#define ASAGI_YON       0           // Kapanma yönü

// Global Konum Değişkenleri (Önceki konuşmalarımızdan)
int current_position_steps = 0; 
const int MAX_STEPS = 1000;     // Perdenin tamamen açılması için gereken toplam adım sayısı
int target_position_steps = 0;

// Function to initialize GPIO pins
void motor_gpio_init() {
    // GPIO Pinlerini çıkış olarak ayarla
    
    gpio_set_direction(MOTOR_STEP_PIN, GPIO_MODE_OUTPUT);

   
    gpio_set_direction(MOTOR_DIR_PIN, GPIO_MODE_OUTPUT);
    
    // Başlangıçta pinleri LOW yap
    gpio_set_level(MOTOR_STEP_PIN, 0);
    gpio_set_level(MOTOR_DIR_PIN, 0);
}
/**
 * DRV8825'e tek bir adım darbesi gönderir.
 * Motor hız ayarı, bu fonksiyon içindeki ets_delay_us() ve 
 * motor_control_task içindeki vTaskDelay() ile yapılır.
 */
void motor_adimi_at(int yon) {
    
    // 1. Yön pinini ayarla
    gpio_set_level(MOTOR_DIR_PIN, yon); 
    
    // 2. STEP pinine kısa bir darbe (pulse) gönder
    
    // a) STEP pinini HIGH yap (Adımı Başlat)
    gpio_set_level(MOTOR_STEP_PIN, 1);
    // Bu gecikme, sürücünün tepki vermesi için minimum süredir (Motor hızını belirlemez)
    ets_delay_us(5); 
    
    // b) STEP pinini LOW yap (Adımı Tamamla)
    gpio_set_level(MOTOR_STEP_PIN, 0);
}

void app_main(void) 
{
    // Initialize motor GPIOs
    motor_gpio_init();

    while (1) 
    {
        printf("Rotating clockwise...\n");
        for (int i = 0; i < STEPS_PER_REVOLUTION; i++)
         {
            motor_adimi_at(YUKARI_YON);
            vTaskDelay(pdMS_TO_TICKS(10)); // Adımlar arasındaki gecikme (hızı ayarlar)
         
        }
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay between rotations

        printf("Rotating counter-clockwise...\n");
        for (int i = 0; i < STEPS_PER_REVOLUTION; i++) 
        {
            motor_adimi_at(ASAGI_YON);
            vTaskDelay(pdMS_TO_TICKS(10)); // Adımlar arasındaki gecikme (hızı ayarlar)
          
        }
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay between rotations
    }
}
