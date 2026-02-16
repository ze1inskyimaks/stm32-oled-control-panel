STM32 OLED Control Panel

Embedded control panel project based on STM32F103 with an SSD1306 OLED display using the u8g2 graphics library over I2C and a rotary encoder for user input.

The project is designed as a structured foundation for building scalable embedded UI systems with clean firmware architecture.

📌 Project Overview

This firmware implements a hardware-driven control panel featuring:

SSD1306 OLED display (128x64)

Hardware I2C communication

u8g2 graphics stack

Rotary encoder input (incremental quadrature)

Button press detection (encoder switch)

Expandable menu system

Modular UI state machine

Future RTOS-ready architecture

🛠 Hardware
MCU

STM32F103C8T6 (Blue Pill)

Display

SSD1306 128x64 OLED (I2C)

Input Device

Incremental rotary encoder (e.g. KY-040 type)
