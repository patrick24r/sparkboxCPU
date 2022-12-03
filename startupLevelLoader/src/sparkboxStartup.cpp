#include "sparkboxStartup.hpp"
#include "main.h"
#include "fatfs.h"

void sparkboxStartupTask(void * argument) {
    while(1) {
        HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
        osDelay(100);
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        osDelay(100);
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
        osDelay(100);
    }
}

