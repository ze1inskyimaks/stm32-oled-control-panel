//
// Created by autoh on 16.02.2026.
//

#ifndef TEST_STM32F103_ROTARY_ENCODER_H
#define TEST_STM32F103_ROTARY_ENCODER_H
#include <stdbool.h>
#include "stm32f1xx_hal.h"

typedef struct {
    GPIO_TypeDef* CLK_port;
    uint16_t CLK_pin;
    GPIO_TypeDef* DT_port;
    uint16_t DT_pin;
    GPIO_TypeDef* SW_port;
    uint16_t SW_pin;
    volatile int32_t position;
} RotaryEncoder_TypeDef;

void RotaryEncoder_Init(
    RotaryEncoder_TypeDef *rotary_encoder,
    GPIO_TypeDef* CLK_port,
    uint16_t CLK_pin,
    GPIO_TypeDef* DT_port,
    uint16_t DT_pin,
    GPIO_TypeDef* SW_port,
    uint16_t SW_pin
    );
void RotaryEncoder_Exti_CallBack(RotaryEncoder_TypeDef *rotary_encoder);
bool RotaryEncoder_ButtonPressed(RotaryEncoder_TypeDef *rotary_encoder);

#endif //TEST_STM32F103_ROTARY_ENCODER_H