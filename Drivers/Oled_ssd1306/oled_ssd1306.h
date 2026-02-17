//
// Created by autoh on 17.02.2026.
//

#ifndef TEST_STM32F103_OLED_SSD1306_H
#define TEST_STM32F103_OLED_SSD1306_H

#include "stm32f1xx_hal.h"
#include "u8g2.h"

extern I2C_HandleTypeDef hi2c1;

void oled_Ssd1306_Init(u8g2_t *u8g2);

#endif //TEST_STM32F103_OLED_SSD1306_H