/*
Proyect MuMa Main
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

//my libs:
#include "GPIO_driver.h"

void intro_print(){

  printf("Proyect MuMa for ESP32\n");

  /* Print chip information */
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
          chip_info.cores,
          (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
          (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  printf("silicon revision %d, ", chip_info.revision);

  printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
          (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
}

void app_main(void){
    unsigned int input_pin=18;

    intro_print();
    printf("output salida %d\n",input_pin);
    //gpio_input_direct_cfg(input_pin);
    gpio_output_direct_cfg(input_pin);

    while(1){

    for (int i = 5; i >= 0; i--) {
         printf("Reading again in %d seconds...\n", i);
         vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    gpio_set_state(input_pin);
    printf("salida!\n");
    
    //printf("The state of the gpio number %d is:  %d\n",input_pin, gpio_get_state(input_pin) );
    //printf("lectura f de ESP:  %d\n", gpio_get_level(22) );

  }


    //Restart after i seconds
    //for (int i = 30; i >= 0; i--) {
    //     printf("Restarting in %d seconds...\n", i);
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // }
    // printf("Restarting now.\n");
    // fflush(stdout);
    // esp_restart();
}
