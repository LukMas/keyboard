/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "pointing_device.h"

// extern inline void icekeys_led_on(void);
// extern inline void icekeys_led_off(void);
//
LEADER_EXTERNS();

enum {
        TD_L_BRACKETS = 0,
        TD_R_BRACKETS
};

qk_tap_dance_action_t tap_dance_actions[] = {
        //Tap once for Esc, twice for Caps Lock
        [TD_L_BRACKETS]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_LPRN),
        [TD_R_BRACKETS]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, KC_RPRN)
// Other declarations would go here, separated by commas, if you have them
};


enum custom_layers {
        _QWERTY,
        _FUNCT
};

enum custom_keys {
        MS_MOD = SAFE_RANGE
};

// enum custom_keycodes {
//         FUNCT,
//         NAVI
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_QWERTY] = { /* Base */
                {              KC_A,         KC_B,              KC_C,        KC_ESC}, \
                {              KC_D,         KC_E,              KC_F,    TT(_FUNCT)}, \
                {            KC_TAB,OSM(MOD_LALT),     OSM(MOD_LCTL), OSM(MOD_LSFT)}, \
                { TD(TD_L_BRACKETS),     KC_SPACE, TD(TD_R_BRACKETS),       KC_LEAD}
        },
        [_FUNCT] = {
                {   KC_1,           KC_2,          KC_3,    KC_0}, \
                {   KC_4,           KC_5,          KC_6, _______}, \
                {   KC_7,         MS_MOD,       _______, _______}, \
                {XXXXXXX,      KC_BSPACE,       XXXXXXX, _______}
        }
};
/* , LT(_NAVI, KC_TAB)
   [_NAVI] = {
         {   KC_MS_BTN1,        KC_MS_UP,     KC_MS_BTN2,   KC_MS_ACCEL2}, \
         {   KC_MS_LEFT,      KC_MS_DOWN,    KC_MS_RIGHT,   KC_MS_ACCEL1}, \
         {      _______,     KC_MS_WH_UP,        _______,   KC_MS_ACCEL0}, \
         {KC_MS_WH_LEFT,   KC_MS_WH_DOWN, KC_MS_WH_RIGHT,        _______}
   } */

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
        // MACRODOWN only works in this function
        switch(id) {
        case 0:
                if (record->event.pressed) {
                        register_code(KC_RSFT);
                } else {
                        unregister_code(KC_RSFT);
                }
                break;
        }
        return MACRO_NONE;
};

// void icekeys_led_on(void) {
//         DDRD |=  (1<<7); PORTD |=  (1<<7);
// }
// void icekeys_led_off(void) {
//         DDRD &=  ~(1<<7); PORTD &=  ~(1<<7);
// }

void matrix_init_user(void) {
        rgblight_enable();
        rgblight_sethsv(0,0,125);
        // rgblight_mode(3);
}

void matrix_scan_user(void) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT) ||
            ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
                rgblight_sethsv_at(0, 125, 125, 1);
                // icekeys_led_on();
        } else {
                rgblight_sethsv_at(0, 0, 125, 1);
        }

        if (keyboard_report->mods & MOD_BIT(KC_LALT) ||
            ((get_oneshot_mods() & MOD_BIT(KC_LALT)) && !has_oneshot_mods_timed_out())) {
                rgblight_sethsv_at(0, 125, 125, 2);
                // icekeys_led_on();
        } else {
                rgblight_sethsv_at(0, 0, 125, 2);
        }

        if (keyboard_report->mods & MOD_BIT(KC_LCTL) ||
            ((get_oneshot_mods() & MOD_BIT(KC_LCTL)) && !has_oneshot_mods_timed_out())) {
                rgblight_sethsv_at(0, 125, 125, 3);
                // icekeys_led_on();
        } else {
                rgblight_sethsv_at(0, 0, 125, 3);
        }

        LEADER_DICTIONARY() {
                leading = false;
                leader_end();

                SEQ_ONE_KEY(KC_A) {
                        // Anything you can do in a macro.
                        SEND_STRING("QMK is awesome.");
                }
                SEQ_TWO_KEYS(KC_A, KC_1) {
                        SEND_STRING("Simulate ALT+1.");
                }
                SEQ_THREE_KEYS(KC_A, KC_B, KC_D) {
                        register_code(KC_LCTRL);
                        register_code(KC_LALT);
                        register_code(KC_LEFT);
                        unregister_code(KC_LEFT);
                        unregister_code(KC_LALT);
                        unregister_code(KC_LCTRL);
                }
                SEQ_THREE_KEYS(KC_A, KC_B, KC_F) {
                        register_code(KC_LCTRL);
                        register_code(KC_LALT);
                        register_code(KC_RIGHT);
                        unregister_code(KC_RIGHT);
                        unregister_code(KC_LALT);
                        unregister_code(KC_LCTRL);
                }
        }
}

report_mouse_t currentReport = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        if (keycode == KC_ESC && record->event.pressed) {
                bool queue = true;

                if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
                        clear_oneshot_mods ();
                        queue = false;
                }

                return queue;
        }

        return true;
}

void led_set_user(uint8_t usb_led) {

}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
        // icekeys_led_off();

        uint8_t layer = biton32(state);
        switch (layer) {
        case 0:
                rgblight_sethsv_at(0, 125, 125, 6);
                rgblight_sethsv_at(0, 0, 125, 7);
                break;
        case 1:
                rgblight_sethsv_at(0, 0, 125, 6);
                rgblight_sethsv_at(0, 125, 125, 7);
                break;
        // case 2:
        // break;
        default:
                break;
        }

        return state;
}
