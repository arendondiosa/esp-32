#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "nvs_flash.h"
#include "nvs.h"

void app_main(void)
{
    printf("Start!\n");

    // Initialize NVS
    esp_err_t err = nvs_flash_init();
    printf("NVM init!\n");
    printf(err != ESP_OK ? "Failed\n" : "Done\n");

    // Open NVS
    nvs_handle_t my_storage;
    err = nvs_open("storage", NVS_READWRITE, &my_storage);
    printf("NVM open!\n");
    printf(err != ESP_OK ? "Failed\n" : "Done\n");

    // Write NVS
    err = nvs_set_i32(my_storage, "my_number", 123);
    printf("NVM Set!\n");
    printf(err != ESP_OK ? "Failed\n" : "Done\n");

    // Save NVS
    err = nvs_commit(my_storage);
    printf("NVM Commit!\n");
    printf(err != ESP_OK ? "Failed\n" : "Done\n");

    // Read NVS
    int32_t my_number;
    err = nvs_get_i32(my_storage, "my_number", &my_number);
    printf("NVM Get!\n");
    printf(err != ESP_OK ? "Failed\n" : "Done\n");

    printf("My number is %ld\n", my_number);

    nvs_close(my_storage);
    printf("NVM close!\n");
}
