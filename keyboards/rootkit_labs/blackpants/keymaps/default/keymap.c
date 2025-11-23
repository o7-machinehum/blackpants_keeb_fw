// Copyright 2025 Solder Party
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum CUSTOM_KEYCODES {
  KC_SPC2 = SAFE_RANGE,
  KC_SPC3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BSPC, KC_0,    KC_MINS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_BSLS, KC_SPC,  KC_SPC2, KC_SPC3, KC_RALT, KC_P,    KC_LBRC,
        KC_LEFT, KC_DOWN, KC_RGHT, KC_SLSH, KC_UP,   KC_RSFT, KC_SCLN, KC_QUOT, KC_PENT, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RBRC
    ),
    [1] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  KC_F11,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, BL_STEP, BL_STEP, BL_STEP, _______, KC_HOME, KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

// Prevent sending multiple space presses if more than one space dome is pressed at the same time
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t space_press_count = 0;

    switch (keycode) {
        case KC_SPC:
        case KC_SPC2:
        case KC_SPC3:
            if (record->event.pressed) {
                if (space_press_count == 0)
                    register_code(KC_SPC);

                space_press_count++;
            } else {
                space_press_count--;

                if (space_press_count == 0)
                  unregister_code(KC_SPC);
            }
            return false;
    }

    return true;
}
