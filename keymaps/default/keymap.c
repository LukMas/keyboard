/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at y our option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *)
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "config.h"

enum CustomLayers {
        _BASE = 0,
        _SYMB,
        _FUNC,
        _NUMS,
        _NAVI
};

enum CustomKeycodes {
        TWO_OR = SAFE_RANGE,
        TWO_AND,
        SG_QUOTE,
        DB_QUOTE
};

// KEYS SHORTCUTS
#define OSM_LCTL  OSM(MOD_LCTL)
#define OSM_LSFT  OSM(MOD_LSFT)
#define OSM_LALT  OSM(MOD_LALT)
#define TO_FUNC   OSL(_FUNC)
#define TO_SYMB   OSL(_SYMB)
#define NAVI_TAB  LT(_NAVI, KC_TAB)
#define NUMS_ESC  LT(_NUMS, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = {
                { NAVI_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,       KC_MINS, /**/ KC_EQL,        KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    NUMS_ESC}, \
                { OSM_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,      KC_G,       KC_LBRC, /**/ KC_RBRC,       KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, OSM_LALT}, \
                {   KC_INS,    KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,      KC_GRAVE, /**/ KC_QUOTE,      KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS}, \
                {    KC_NO, KC_HOME, KC_PGUP,  KC_END, TO_FUNC,    KC_SPC,      OSM_LSFT, /**/ KC_BSPC,       KC_ENT,     TO_SYMB, KC_LEFT, KC_UP,   KC_RGHT, KC_RALT}, \
                {    KC_NO,   KC_NO, KC_PGDN,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_DOWN, KC_NO,   KC_NO}
        },
        [_SYMB] = {
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    TWO_OR,       KC_PIPE, /**/ KC_AMPR,       TWO_AND,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ESC}, \
                {  KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,      KC_5,       KC_LPRN, /**/ KC_RPRN,       KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS}, \
                {  KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,      SG_QUOTE, /**/ DB_QUOTE,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,       KC_TRNS, /**/ KC_TRNS,       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, \
                {    KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO}
        },
        [_FUNC] = {
                {    KC_NO,   KC_F9,  KC_F10,  KC_F12,   KC_NO,     KC_NO,        KC_APP, /**/ KC_LGUI,       KC_NO,      KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_ESC}, \
                {  KC_TRNS,   KC_F7,   KC_F8,   KC_F8,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_F1,   KC_F2,   KC_F3,   KC_NO,   KC_TRNS}, \
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,       KC_TRNS, /**/ KC_DEL,        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}, \
                {    KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO}
        },
        [_NUMS] = {
                {    KC_NO,   KC_NO,    KC_7,    KC_8,    KC_9,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS}, \
                {    KC_NO,   KC_NO,    KC_4,    KC_5,    KC_6,    KC_DOT,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {    KC_NO,   KC_NO,    KC_1,    KC_2,    KC_3,   KC_SLSH,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {    KC_NO,   KC_NO,    KC_0,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}
        },
        [_NAVI] = {
                {  KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_WH_U, KC_NO,   KC_NO,   RESET}, \
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_WH_L, KC_WH_D, KC_WH_R, KC_NO,   KC_NO}, \
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
                {    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,         KC_NO, /**/ KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}
        }
};
// {           KC_ESC,    KC_Q,    KC_W,    KC_E,      KC_R,    KC_T}, ,              KC_T,/**/ KC_Y,              KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,     KC_INS},
// {             KC_A,    KC_A,    KC_S,    KC_D,      KC_F,    KC_G},               KC_G,/**/ KC_H,              KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN,  KC_LGUI},
// {           KC_APP,    KC_Z,    KC_X,    KC_C,      KC_V,    KC_B},       TD(OSM_CTL),/**/ OSM_ALT,           KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  KC_RALT },
// {            KC_NO, KC_HOME, KC_PGUP,  KC_END,    KC_SPC,  KC_SPC},            OSM_SFT,/**/ KC_BSPC,           KC_ENT,  KC_ENT,    KC_LEFT, KC_UP,   KC_RIGHT, RESET},
// {            KC_NO,   KC_NO, KC_PGDN,   KC_NO,     KC_NO,   KC_NO}               KC_NO,/**/ KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_DOWN, KC_NO,    KC_NO}


//
// {LT(_NAVI, KC_TAB),    KC_A,    KC_S,    KC_D,      KC_F,    KC_G, TD(TD_L_BRACKETS),        TD(TD_R_BRACKETS), KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN,  KC_LGUI},
// {           KC_ESC,    KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,     TD(TD_MIN_AC),        TD(TD_EQL_GR),     KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,     KC_INS},
// {            KC_NO, KC_HOME, KC_PGUP,  KC_END,OSL(_FUNC),  KC_SPC,           OSM_SFT,        KC_BSPC,           KC_ENT,  OSL(_SYMB),KC_LEFT, KC_UP,   KC_RIGHT, MO(_MEDIA)},
// [_FUNC] = {
//         {          KC_TRNS,   KC_NO,  KC_F10,  KC_F11,    KC_F12,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_F4,     KC_F5,   KC_F6,   KC_NO,    KC_TRNS},
//         {          KC_TRNS,   KC_NO,   KC_F7,   KC_F8,     KC_F9,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_F1,     KC_F2,   KC_F3,   KC_NO,    KC_TRNS},
//         {          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,           KC_TRNS,      KC_TRNS,           KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_TRNS},
//         {          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_NO,           KC_TRNS,      KC_DEL,            KC_NO,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
//         {            KC_NO,   KC_NO, KC_TRNS,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_TRNS, KC_NO,    KC_NO}
// },
// [_SYMB] = {
//         {          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_TRNS},
//         {          KC_TRNS,    KC_1,    KC_2,    KC_3,      KC_4,    KC_5,             KC_NO,      KC_NO,             KC_6,    KC_7,      KC_8,    KC_9,    KC_0,     KC_TRNS},
//         {          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,           KC_TRNS,      KC_TRNS,           KC_NO,   KC_GRV,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
//         {          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_NO,           KC_TRNS,      KC_TRNS,           KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
//         {            KC_NO,   KC_NO, KC_TRNS,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_TRNS, KC_NO,    KC_NO}
// },
// [_NAVI] = {
//         {            KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_WH_U, KC_NO,   KC_NO,    KC_NO},
//         {            KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_WH_L,   KC_WH_D, KC_WH_R, KC_NO,    KC_NO},
//         {            KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,           KC_TRNS,      KC_TRNS,           KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO},
//         {          KC_TRNS,CK_DSK_L, KC_TRNS,CK_DSK_R,   KC_TRNS,   KC_NO,           KC_TRNS,      KC_TRNS,           KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO},
//         {            KC_NO,   KC_NO, KC_TRNS,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_TRNS, KC_NO,    KC_NO}
// },
// [_MEDIA] = {
//         {          KC_SLEP,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    RESET},
//         {            KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO},
//         {            KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO},
//         {          KC_TRNS, KC_MPRV, KC_VOLU, KC_MNXT,   KC_MPLY, KC_MUTE,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_TRNS},
//         {            KC_NO,   KC_NO, KC_VOLD,   KC_NO,     KC_NO,   KC_NO,             KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO}
// }
//

void matrix_init_user(void) {
        rgblight_enable_noeeprom();
        // rgblight_sethsv(0,0,125);
}



void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
        case TWO_AND:
                if (record->event.pressed) {
                        // when keycode QMKBEST is pressed
                        SEND_STRING(" && ");
                }
                break;

        case TWO_OR:
                if (record->event.pressed) {
                        // when keycode QMKBEST is pressed
                        SEND_STRING(" || ");
                }
                break;

        case SG_QUOTE:
                if (record->event.pressed) {
                        SEND_STRING("' ");
                }
                break;

        case DB_QUOTE:
                if (record->event.pressed) {
                        // when keycode QMKBEST is pressed
                        SEND_STRING("\" ");
                }
                break;

        }
        return true;
};

void oneshot_mods_changed_kb(uint8_t mods) {
        if (mods & MOD_MASK_SHIFT) {
                rgblight_setrgb_at(80, 0, 0, 6);
        }
        if (mods & MOD_MASK_CTRL) {
                rgblight_setrgb_at(80, 0, 0, 7);
        }
        if (mods & MOD_MASK_ALT) {
                rgblight_setrgb_at(80, 0, 0, 5);
        }

        if (!mods) {
                rgblight_setrgb_at(0, 0, 0, 7);
                rgblight_setrgb_at(0, 0, 0, 6);
                rgblight_setrgb_at(0, 0, 0, 5);
        }
}

void oneshot_locked_mods_changed_kb(uint8_t mods) {
        if (mods & MOD_MASK_SHIFT) {
                rgblight_setrgb_at(160, 0, 0, 6);
        }
        if (mods & MOD_MASK_CTRL) {
                rgblight_setrgb_at(160, 0, 0, 7);
        }
        if (mods & MOD_MASK_ALT) {
                rgblight_setrgb_at(160, 0, 0, 5);
        }

        if (!mods) {
                rgblight_setrgb_at(0, 0, 0, 7);
                rgblight_setrgb_at(0, 0, 0, 6);
                rgblight_setrgb_at(0, 0, 0, 5);
        }
}


uint32_t layer_state_set_user(uint32_t state) {
        // icekeys_led_off();

        uint8_t layer = biton32(state);
        switch (layer) {
        case _SYMB:
                rgblight_setrgb_at(160, 0, 0, 0);
                break;
        case _FUNC:
                rgblight_setrgb_at(160, 0, 0, 1);
                break;
        case _NUMS:
                rgblight_setrgb_at(160, 0, 0, 2);
                break;
        case _NAVI:
                rgblight_setrgb_at(160, 0, 0, 3);
                break;
        // case 2:
        // break;
        default:
                rgblight_setrgb_at(0, 0, 0, 0);
                rgblight_setrgb_at(0, 0, 0, 1);
                rgblight_setrgb_at(0, 0, 0, 2);
                rgblight_setrgb_at(0, 0, 0, 3);
                break;
        }

        return state;
}
