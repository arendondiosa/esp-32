#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t taskHandle1 = NULL;

void task1(void *args)
{
    while(1) {
        printf("Task1\n");
    }
}

void app_main(void)
{
    xTaskCreate(task1, "task1", 4096, NULL, 10, &taskHandle1);
}
