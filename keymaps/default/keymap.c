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
#include "config.h"


// one-shot modifier keys
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)

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
        _FUNC,
        _SYMB,
        _NAVI
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
                {           KC_ESC,    KC_Q,    KC_W,   KC_E,      KC_R,    KC_T, TD(TD_L_BRACKETS), /* MIDDLE */ TD(TD_R_BRACKETS), KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,     KC_LGUI}, \
                { LT(_NAVI,KC_TAB),    KC_A,    KC_S,   KC_D,      KC_F,    KC_G,           KC_MINS, /* MIDDLE */ KC_EQL,            KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN,  KC_LEAD}, \
                {           KC_APP,    KC_Z,    KC_X,   KC_C,      KC_V,    KC_B,           OSM_CTL, /* MIDDLE */ OSM_ALT,           KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  ALGR_T(KC_INS) }, \
                {            KC_NO, KC_HOME, KC_PGUP, KC_END, TT(_FUNC),  KC_SPC,           OSM_SFT, /* MIDDLE */ KC_BSPC,           KC_ENT,  TT(_SYMB), KC_LEFT, KC_UP,   KC_RIGHT, KC_NO}, \
                {            KC_NO,   KC_NO, KC_PGDN,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_DOWN, KC_NO,    KC_NO}
        },

        [_FUNC] = {
                {           KC_ESC,   KC_NO,  KC_F10, KC_F11,    KC_F12,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_F4,     KC_F5,   KC_F6,   KC_NO,    KC_NO}, \
                {   KC_TRANSPARENT,   KC_NO,   KC_F7,  KC_F8,     KC_F9,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_F1,     KC_F2,   KC_F3,   KC_NO,    KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO, TT(_FUNC),   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   TT(_SYMB), KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO}
        },

        [_SYMB] = {
                {           KC_ESC,   KC_NO,   KC_NO,  KC_NO,   KC_DQUO, KC_BSLS,             KC_NO, /* MIDDLE */ KC_NO,             KC_PIPE, KC_QUOT,   KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {   KC_TRANSPARENT,    KC_1,    KC_2,   KC_3,      KC_4,    KC_5,             KC_NO, /* MIDDLE */ KC_NO,             KC_6,    KC_7,      KC_8,    KC_9,    KC_0,     KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TILD,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_GRV,    KC_NO,   KC_NO,   KC_NO,    KC_TRANSPARENT}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO, TT(_FUNC),  KC_DEL,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   TT(_SYMB), KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO}
        },

        [_NAVI] = {
                {           KC_ESC,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {   KC_TRANSPARENT,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TILD,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_GRV,    KC_NO,   KC_NO,   KC_NO,    KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO, TT(_FUNC),  KC_DEL,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   TT(_SYMB), KC_WH_L, KC_WH_U, KC_WH_R,  KC_NO}, \
                {            KC_NO,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,             KC_NO, /* MIDDLE */ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_WH_D, KC_NO,    KC_NO}
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
                rgblight_sethsv_at(0, 125, 125, 14);
                rgblight_sethsv_at(0, 0, 125, 15);
                break;
        case 1:
                rgblight_sethsv_at(0, 0, 125, 6);
                rgblight_sethsv_at(0, 125, 125, 7);
                rgblight_sethsv_at(0, 0, 125, 14);
                rgblight_sethsv_at(0, 125, 125, 15);
                break;
        // case 2:
        // break;
        default:
                break;
        }

        return state;
}
