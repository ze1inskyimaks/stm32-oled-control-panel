//
// Created by autoh on 23.02.2026.
//

#ifndef TEST_STM32F103_SYSTEM_MENU_H
#define TEST_STM32F103_SYSTEM_MENU_H
#include <stdint.h>

#include "rotary_encoder.h"

typedef struct {
    uint16_t value;
    uint16_t max;
} CircleProgress_t;

typedef struct {
    void (*item_draw)(void *context, uint8_t selected_flag);
    void (*item_function)();
    uint8_t item_index;
    void *context;
} MenuItem_t;

typedef struct {
    char name[16];
    MenuItem_t *items;
    uint8_t item_count;
    uint8_t item_selected;
} MenuPage_t;

typedef struct {
    MenuPage_t *pages;
    uint8_t page_count;
    uint8_t page_selected;
} Menu_t;

void menu_init(RotaryEncoder_TypeDef* rotaryEncoder);
void menu_page_Render();
void menu_change_position();
void menu_press_button();

#endif //TEST_STM32F103_SYSTEM_MENU_H