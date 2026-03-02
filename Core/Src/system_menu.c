//
// Created by autoh on 23.02.2026.
//

#include "system_menu.h"

#include <stdio.h>

#include "ssd1306.h"

#define ARROW_Y 40

static RotaryEncoder_TypeDef* rotaryEncoder;

static Menu_t mainMenu;

static void DrawCircleProgress(void *context, uint8_t selected);
static void DrawLeftArrow(void *context, uint8_t selected);
static void DrawRightArrow(void *context, uint8_t selected);

void menu_init(RotaryEncoder_TypeDef* rotary_encoder) {
    rotaryEncoder = rotary_encoder;
}

void menu_page_Render() {
    MenuPage_t page = mainMenu.pages[mainMenu.page_selected];
    for (uint8_t i = 0; i < page.item_count; i++) {
        uint8_t selected_flag = 0;
        if ((int)rotaryEncoder->position == i) {
            selected_flag = 1;
        }
        MenuItem_t item = page.items[i];
        mainMenu.pages[mainMenu.page_selected].items[i].item_draw(item.context, selected_flag);
    }
}

void menu_press_button() {
    MenuPage_t page = mainMenu.pages[mainMenu.page_selected];
    uint8_t pos = (uint8_t)rotaryEncoder->position;

    if (page.items[pos].item_function != NULL) {
        page.items[pos].item_function();
    }

    menu_page_Render();
}

void menu_change_position() {
    float pos = rotaryEncoder->position;

    if (pos < 0)
        pos = 0;

    if (pos >= (float)mainMenu.pages[0].item_count)
        pos = (float)mainMenu.pages[0].item_count - 1;

    rotaryEncoder->position = pos;

    menu_page_Render();
}

static CircleProgress_t circle1 =
{
    .value = 10,
    .max   = 40
};

static MenuItem_t mainMenuItems[] =
{
    {
        .item_draw = DrawLeftArrow,
        .item_function = NULL,
        .context = NULL,
        .item_index = 0
    },
    {
        .item_draw = DrawCircleProgress,
        .context = &circle1,
        .item_index = 1
    },
    {
        .item_draw = DrawRightArrow,
        .context = NULL,
        .item_index = 2
    }
};

static MenuPage_t mainMenuPages[] =
{
    {
        .name = "Main",
        .items = mainMenuItems,
        .item_count = sizeof(mainMenuItems) / sizeof(mainMenuItems[0])
    }
};

static Menu_t mainMenu =
{
    .pages = mainMenuPages,
    .page_count = sizeof(mainMenuPages) / sizeof(mainMenuPages[0]),
    .page_selected = 0
};

/*void MainPage() {
    ssd1306_Clear();

    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Main", Font_7x10);
    // лінія під header
    ssd1306_DrawHorizontalLine(0, 12, SSD1306_WIDTH);

    // ліва
    ssd1306_DrawTriangle(5, ARROW_Y, 15, ARROW_Y - 5, 15, ARROW_Y + 5);
    // права
    ssd1306_DrawTriangle(123, ARROW_Y, 113, ARROW_Y - 5, 113, ARROW_Y + 5);

    DrawCircleProgress(10, 40, 0);
}*/

static void DrawCircleProgress(void *context, uint8_t selected) {
    CircleProgress_t *circle = (CircleProgress_t *)context;

    uint16_t value = circle->value;
    uint16_t max   = circle->max;

    uint8_t centerX = SSD1306_WIDTH / 2;
    uint8_t centerY = 40;
    uint8_t radius = 18;

    uint16_t angle = (360U * value) / max;

    if (selected) {
        ssd1306_DrawCircle(centerX, centerY, radius + 3);
    }

    // рамка
    ssd1306_DrawCircle(centerX, centerY, radius);

    // прогрес
    ssd1306_DrawArc(centerX, centerY, radius - 2, 0, angle);

    // число всередині
    char buf[8];
    sprintf(buf, "%u", value);

    ssd1306_SetCursor(centerX - 8, centerY - 5);
    ssd1306_WriteString(buf, Font_7x10);

    ssd1306_SetColor(White);
}

static void DrawLeftArrow(void *context, uint8_t selected) // 0 - nothing, 1 - selected
{
    (void)context;

    if (selected == 1) {
        ssd1306_DrawLine(5, ARROW_Y + 10, 15, ARROW_Y + 10);
    }

    ssd1306_DrawTriangle(5, ARROW_Y,
                         15, ARROW_Y - 5,
                         15, ARROW_Y + 5);

}

static void DrawRightArrow(void *context, uint8_t selected) // 0 - nothing, 1 - selected
{
    (void)context;

    if (selected == 1) {
        ssd1306_DrawLine(113, ARROW_Y + 10, 123, ARROW_Y + 10);
    }
    ssd1306_DrawTriangle(123, ARROW_Y,
                         113, ARROW_Y - 5,
                         113, ARROW_Y + 5);
}