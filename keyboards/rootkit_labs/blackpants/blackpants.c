// Copyright 2025 Solder Party
// SPDX-License-Identifier: GPL-2.0-or-later

#include "hal.h"

#define USB_CS_PIN 14
#define USB_CS_PORT GPIOC

#define USB_DET_PIN 13
#define USB_DET_PORT GPIOC

#define LED_PIN 4
#define LED_PORT GPIOB

void board_init(void) {
    palSetPadMode(LED_PORT, LED_PIN, PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(LED_PORT, LED_PIN);

    palSetPadMode(USB_DET_PORT, USB_DET_PIN, PAL_MODE_INPUT);
    palSetPadMode(USB_CS_PORT, USB_CS_PIN, PAL_MODE_OUTPUT_PUSHPULL);

    // If we're plugged in (USB-C) then mux STM32's input to this
    // usb port else mux it to the blackhat.
    if(palReadPad(USB_DET_PORT, USB_DET_PIN)) {
        palClearPad(LED_PORT, LED_PIN);
        palClearPad(USB_CS_PORT, USB_CS_PIN);
    }
    else {
        palSetPad(LED_PORT, LED_PIN);
        palSetPad(USB_CS_PORT, USB_CS_PIN);
    }
}
