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

bool isDefaultLayer = true;

enum CustomLayers {
        _BASE = 0,
        _SYMB,  // symbols
        _FUNC,  // func keys
        _NUMS,  // num keypad on left side
        _NVMD   // media and navigation keys
};

enum CustomKeycodes {
        TWO_OR = SAFE_RANGE,
        TWO_AND,
        SG_QUOTE,
        DB_QUOTE,
        W_LS,
        W_LD,
        GO_L,
        W_RS,
        W_RD,
        GO_R
};

// KEYS SHORTCUTS
#define OSM_LCTL  OSM(MOD_LCTL)
#define OSM_LSFT  OSM(MOD_LSFT)
#define OSM_LALT  OSM(MOD_LALT)
#define OSM_LCSA  OSM(MOD_LCTL | MOD_LSFT | MOD_LALT)
#define TO_FUNC   OSL(_FUNC)
#define TO_SYMB   OSL(_SYMB)
#define NVMD_TAB  LT(_NVMD, KC_TAB)
#define NUMS_ESC  LT(_NUMS, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT(
                 NVMD_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,   KC_MINS, /**/ KC_EQL,   KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    NUMS_ESC, \
                 OSM_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,      KC_G,   KC_LBRC, /**/ KC_RBRC,  KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, OSM_LCTL, \
                 OSM_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,  KC_GRAVE, /**/ KC_QUOTE, KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM_LSFT, \
                 OSM_LALT, KC_HOME, KC_PGUP,  KC_END, TO_FUNC,    KC_SPC,    KC_DEL, /**/ KC_BSPC,  KC_ENT,     TO_SYMB, KC_LEFT, KC_UP,   KC_RGHT, KC_RALT, \
                                    KC_PGDN,                                         /**/                                         KC_DOWN
        ),
        [_SYMB] = LAYOUT(
                   KC_TAB,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    TWO_OR,   KC_PIPE, /**/ KC_AMPR,  TWO_AND,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ESC, \
                  KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,      KC_5,   KC_LPRN, /**/ KC_RPRN,  KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, \
                  KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,  SG_QUOTE, /**/ DB_QUOTE, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,   KC_TRNS,   KC_TRNS, /**/ KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS, \
                                    KC_TRNS,                                         /**/                                         KC_TRNS
        ),
        [_FUNC] = LAYOUT(
                   KC_TAB,   KC_NO,  KC_F10,   KC_F11, KC_F12,     KC_NO,    KC_APP, /**/ KC_LGUI,  KC_NO,      KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_ESC, \
                  KC_TRNS,   KC_NO,   KC_F7,   KC_F8,   KC_F9,     KC_NO,     KC_NO, /**/ KC_NO,    KC_NO,      KC_F1,   KC_F2,   KC_F3,   KC_NO,   KC_TRNS, \
                  KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO, /**/ KC_NO,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, \
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, /**/ KC_INS,   KC_TRNS,    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS,                                         /**/                                         KC_TRNS
        ),
        [_NUMS] = LAYOUT(
                    KC_NO,   KC_NO,    KC_7,    KC_8,    KC_9,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, \
                    KC_NO,   KC_NO,    KC_4,    KC_5,    KC_6,    KC_DOT,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
                    KC_NO,   KC_NO,    KC_1,    KC_2,    KC_3,   KC_SLSH,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
                    KC_NO,   KC_NO,    KC_0,   KC_NO,   KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
                                      KC_NO,                                        /**/                                          KC_NO
        ),
        [_NVMD] = LAYOUT(
                  KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,   KC_WH_U, KC_NO,   KC_NO,   RESET, \
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_WH_L, KC_WH_D, KC_WH_R, KC_NO,   KC_NO, \
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_MUTE, KC_NO,   KC_NO, \
                  KC_SLEP,   KC_NO,   KC_NO,   KC_NO,    W_LS,      W_LD,     GO_L, /**/  GO_R,     W_RD,       W_RS,    KC_MPRV, KC_VOLU, KC_MNXT, KC_MPLY, \
                                      KC_NO,                                        /**/                                          KC_VOLD
        )
};

void matrix_init_user(void) {
        rgblight_enable_noeeprom();
}



void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
        case KC_ESC:
                if (record->event.pressed) {
                        bool queue = true;

                        if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
                            clear_oneshot_mods ();
                            queue = false;
                        }
                    if (!isDefaultLayer) {
                            reset_oneshot_layer();
                            queue = false;
                        }

                        return queue;
                }
                break;

        case TWO_AND:
                if (record->event.pressed) {
                        SEND_STRING(" && ");
                }
                break;

        case TWO_OR:
                if (record->event.pressed) {
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
                        SEND_STRING("\" ");
                }
                break;

        case W_LS:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LGUI));
                        SEND_STRING(SS_TAP(X_LEFT));
                        SEND_STRING(SS_UP(X_LGUI));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case W_RS:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LGUI));
                        SEND_STRING(SS_TAP(X_RIGHT));
                        SEND_STRING(SS_UP(X_LGUI));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case W_LD:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_LEFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case W_RD:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_RIGHT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case GO_L:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_LEFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case GO_R:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_RIGHT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
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
                isDefaultLayer = false;
                rgblight_setrgb_at(160, 0, 0, 0);
                break;
        case _FUNC:
                isDefaultLayer = false;
                rgblight_setrgb_at(160, 0, 0, 1);
                break;
        case _NUMS:
                isDefaultLayer = false;
                rgblight_setrgb_at(160, 0, 0, 2);
                break;
        case _NVMD:
                isDefaultLayer = false;
                rgblight_setrgb_at(160, 0, 0, 3);
                break;
        // case 2:
        // break;
        default:
                isDefaultLayer = true;
                rgblight_setrgb_at(0, 0, 0, 0);
                rgblight_setrgb_at(0, 0, 0, 1);
                rgblight_setrgb_at(0, 0, 0, 2);
                rgblight_setrgb_at(0, 0, 0, 3);
                break;
        }

        return state;
}
