#ifndef INC_SPARKBOX_HOST_HPP_
#define INC_SPARKBOX_HOST_HPP_

// Global includes
#include "sparkboxErrors.hpp"
#include <string>

// Platform includes
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"
#include "cmsis_os2.h"

sparkboxError_t sparkboxInitialize();

#endif // !INC_SPARKBOX_HOST_HPP_
