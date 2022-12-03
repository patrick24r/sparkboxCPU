#include "sparkboxStartup.hpp"
#include "main.h"
#include "fatfs.h"
#include "usb_host.h"

extern volatile ApplicationTypeDef Appli_state;

void test_fatfs();

void sparkboxStartupTask(void * argument) {

    // Wait for USB drive to be inserted
    while (Appli_state != APPLICATION_READY) {
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
        osDelay(500);
    }

    test_fatfs();

    while(1) {
        HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
        osDelay(100);
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        osDelay(100);
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
        osDelay(100);
    }
}


void test_fatfs()
{

}
