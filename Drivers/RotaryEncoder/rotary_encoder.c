//
// Created by autoh on 16.02.2026.
//

#include "rotary_encoder.h"

void RotaryEncoder_Init(
    RotaryEncoder_TypeDef *rotary_encoder,
    GPIO_TypeDef* CLK_port,
    uint16_t CLK_pin,
    GPIO_TypeDef* DT_port,
    uint16_t DT_pin,
    GPIO_TypeDef* SW_port,
    uint16_t SW_pin
    )
{
    rotary_encoder->CLK_port = CLK_port;
    rotary_encoder->CLK_pin = CLK_pin;
    rotary_encoder->DT_port = DT_port;
    rotary_encoder->DT_pin 	= DT_pin;
    rotary_encoder->SW_port = SW_port;
    rotary_encoder->SW_pin 	= SW_pin;
    rotary_encoder->position = 0;
}
void RotaryEncoder_Exti_CallBack(RotaryEncoder_TypeDef *rotary_encoder) {
    if (HAL_GPIO_ReadPin(rotary_encoder->CLK_port , rotary_encoder->CLK_pin) !=
        HAL_GPIO_ReadPin(rotary_encoder->DT_port , rotary_encoder->DT_pin)) {
        rotary_encoder->position++;
    }
    else {
        rotary_encoder->position--;
    }
}

bool RotaryEncoder_ButtonPressed(RotaryEncoder_TypeDef *rotary_encoder) {
    return HAL_GPIO_ReadPin(rotary_encoder->SW_port, rotary_encoder->SW_pin) == GPIO_PIN_RESET;
}