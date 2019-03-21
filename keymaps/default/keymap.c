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

enum TapDanceKeycodes {
        L_PRT_CTRL,
        R_PRT_CTRL,
        L_BRK_SHIFT,
        R_BRK_SHIFT,
        L_SQRB_ALT,
        R_SQRB_ALT
};

uint8_t isDefaultLayer = _BASE;
const uint8_t MODS_TAP_COUNT = 2;

#define TO_FUNC    TT(_FUNC)
#define TO_SYMB    TT(_SYMB)
#define NVMD_TAB   LT(_NVMD, KC_TAB)
#define NUMS_ESC   LT(_NUMS, KC_ESC)
#define TD_L_PT_CR TD(L_PRT_CTRL)
#define TD_R_PT_CR TD(R_PRT_CTRL)
#define TD_L_BR_SH TD(L_BRK_SHIFT)
#define TD_R_BR_SH TD(R_BRK_SHIFT)
#define TD_L_SQ_AL TD(L_SQRB_ALT)
#define TD_R_SQ_AL TD(R_SQRB_ALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT(
                    NVMD_TAB,     KC_Q,     KC_W,    KC_E,     KC_R,      KC_T,   KC_LEAD, /**/  \
                  TD_L_PT_CR,     KC_A,     KC_S,    KC_D,     KC_F,      KC_G,    KC_EQL, /**/  \
                  TD_L_BR_SH,     KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,   KC_LGUI, /**/  \
                  TD_L_SQ_AL,  KC_HOME,  KC_PGUP,  KC_END,  TO_FUNC,    KC_SPC,    KC_INS, /**/  \
                                         KC_PGDN,                                          /**/  \
                                                                    KC_DEL,   KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,    NUMS_ESC,    \
                                                                    KC_MINS,  KC_H,       KC_J,     KC_K,     KC_L,     KC_SCLN, TD_R_PT_CR,  \
                                                                    KC_APP,   KC_N,       KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, TD_R_BR_SH,  \
                                                                    KC_BSPC,  KC_ENT,     TO_SYMB,  KC_LEFT,  KC_UP,    KC_RGHT, TD_R_SQ_AL,  \
                                                                                                              KC_DOWN
        ),
        [_SYMB] = LAYOUT(
                      KC_TAB,    KC_NO,  SG_QUOTE,   KC_GRV,   TWO_OR,  KC_PIPE,     KC_NO, /**/  \
                     KC_LCTL,     KC_1,      KC_2,     KC_3,     KC_4,     KC_5,     KC_NO, /**/  \
                     KC_LSFT,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO, /**/  \
                     KC_LALT,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_LALT,  KC_LSFT,     KC_NO, /**/  \
                                          KC_TRNS,                                          /**/  \
                                                                    KC_NO,    KC_AMPR,    TWO_AND,  KC_QUOT,  DB_QUOTE, KC_NO,   KC_ESC,      \
                                                                    KC_NO,    KC_6,       KC_7,     KC_8,     KC_9,     KC_0,    KC_RCTL,     \
                                                                    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_RSFT,     \
                                                                    KC_NO,    KC_NO,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BSLS, KC_ALGR,     \
                                                                                                              KC_TRNS
        ),
        [_FUNC] = LAYOUT(
                      KC_TAB,     KC_NO,   KC_F10,   KC_F11,   KC_F12,     KC_NO,     KC_NO, /**/  \
                     KC_LCTL,     KC_NO,    KC_F7,    KC_F8,    KC_F9,     KC_NO,     KC_NO, /**/  \
                     KC_LSFT,     KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO, /**/  \
                     KC_LALT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_NO,     KC_NO, /**/  \
                                          KC_TRNS,                                           /**/  \
                                                                    KC_NO,    KC_NO,      KC_F4,      KC_F5,    KC_F6,    KC_NO,     KC_ESC,      \
                                                                    KC_NO,    KC_NO,      KC_F1,      KC_F2,    KC_F3,    KC_NO,     KC_RCTL,     \
                                                                    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,     KC_RSFT,     \
                                                                    KC_NO,    KC_LSFT,    KC_LALT,    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_ALGR,     \
                                                                                                                KC_TRNS
        ),
        [_NUMS] = LAYOUT(
                    KC_NO,   KC_NO,     KC_7,    KC_8,     KC_9,   KC_MINS,    KC_NO, /**/  \
                    KC_NO,   KC_NO,     KC_4,    KC_5,     KC_6,    KC_DOT,    KC_NO, /**/  \
                    KC_NO,   KC_NO,     KC_1,    KC_2,     KC_3,   KC_SLSH,    KC_NO, /**/  \
                    KC_NO,   KC_NO,     KC_0,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/  \
                                       KC_NO,                                         /**/  \
                                                                    KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_TRNS, \
                                                                    KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   \
                                                                    KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   \
                                                                    KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   \
                                                                                                               KC_NO
        ),
        [_NVMD] = LAYOUT(
                  KC_TRNS,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ \
                    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ \
                  KC_WAKE,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ \
                  KC_SLEP,   KC_NO,    KC_NO,   KC_NO,     W_LS,      W_LD,     GO_L, /**/ \
                                       KC_NO,                                         /**/ \
                                                                    KC_NO,     KC_NO,      KC_NO,    KC_WH_U,  KC_NO,    KC_NO,   RESET,   \
                                                                    KC_NO,     KC_NO,      KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_NO,   KC_NO,   \
                                                                    KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_MUTE,  KC_NO,   KC_NO,   \
                                                                    GO_R,      W_RD,       W_RS,     KC_MPRV,  KC_VOLU,  KC_MNXT, KC_MPLY, \
                                                                                                               KC_VOLD
        )
};


uint8_t ledsRed[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t ledsGrn[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t ledsBlu[8] = {0, 0, 0, 0, 0, 0, 0, 0};


inline void changeLight(uint8_t ledA, uint8_t ledB, uint8_t value){
    ledsRed[ledA] += value;
    ledsGrn[ledA] += value;
    ledsBlu[ledA] += value; 
    
    ledsRed[ledB] += value;
    ledsGrn[ledB] += value;
    ledsBlu[ledB] += value;
    
    rgblight_setrgb_at(ledsRed[ledA], ledsGrn[ledA], ledsBlu[ledA], ledA);
    rgblight_setrgb_at(ledsRed[ledB], ledsGrn[ledB], ledsBlu[ledB], ledB);
}

// C O N T R O L
void dance_l_ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        register_mods(MOD_BIT(KC_LSFT));
        register_code(KC_9);
        
  } else {
        changeLight(7, 6, 40);
        
        register_mods(MOD_BIT(KC_LCTL));
  }
}

void dance_l_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        unregister_code(KC_9);
        unregister_mods(MOD_BIT(KC_LSFT));
        
    } else {
        changeLight(7, 6, -40);
        
        unregister_mods(MOD_BIT(KC_LCTL));
    }
}

void dance_r_ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        register_mods(MOD_BIT(KC_RSFT));
        register_code(KC_0);
    } else {
        changeLight(0, 1, 40);

        register_mods(MOD_BIT(KC_RCTL));
  }
}

void dance_r_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        unregister_code(KC_0);
        unregister_mods(MOD_BIT(KC_RSFT));
        
    } else {
        changeLight(0, 1, -40);
        
        unregister_mods(MOD_BIT(KC_RCTL));
    }
}

// S H I F T
void dance_l_shift_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        register_mods(MOD_BIT(KC_LSFT));
        register_code(KC_LBRC);
        
  } else {
        changeLight(6, 5, 40);
        
        register_mods(MOD_BIT(KC_LSFT));
  }
}

void dance_l_shift_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        unregister_code(KC_LBRC);
        unregister_mods(MOD_BIT(KC_LSFT));
        
    } else {
        changeLight(6, 5, -40);
        
        unregister_mods(MOD_BIT(KC_LSFT));
    }
}

void dance_r_shift_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        register_mods(MOD_BIT(KC_RSFT));
        register_code(KC_RBRC);
        
  } else {
        changeLight(1, 2, 40);

        register_mods(MOD_BIT(KC_RSFT));
  }
}

void dance_r_shift_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        unregister_code(KC_RBRC);
        unregister_mods(MOD_BIT(KC_RSFT));
        
    } else {
        changeLight(1, 2, -40);
    
        unregister_mods(MOD_BIT(KC_RSFT));
    }
}

// A L T
void dance_l_alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        register_code(KC_LBRC);
        
  } else {
        changeLight(5, 4, 40);

        register_mods(MOD_BIT(KC_LALT));
  }
}

void dance_l_alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        unregister_code(KC_LBRC);
        
    } else {
        changeLight(5, 4, -40);
        
        unregister_mods(MOD_BIT(KC_LALT));
    }
}

void dance_r_alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        register_code(KC_RBRC);
        
    } else {
        changeLight(2, 3, 40);
        
        register_mods(MOD_BIT(KC_ALGR));
  }
}

void dance_r_alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == MODS_TAP_COUNT) {
        unregister_code(KC_RBRC);
        
    } else {
        changeLight(2, 3, -40);
        
        unregister_mods(MOD_BIT(KC_ALGR));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [L_PRT_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_l_ctrl_finished, dance_l_ctrl_reset),
    [R_PRT_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_ctrl_finished, dance_r_ctrl_reset),
    [L_BRK_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_l_shift_finished, dance_l_shift_reset),
    [R_BRK_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_shift_finished, dance_r_shift_reset),
    [L_SQRB_ALT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_l_alt_finished, dance_l_alt_reset),
    [R_SQRB_ALT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_alt_finished, dance_r_alt_reset)
};


LEADER_EXTERNS();

uint8_t keyPresses[6] = {0,0,0,0,0,0};

void leader_start(void) {
                rgblight_setrgb_at(130, 130, 130, 4);
}

void leader_end(void) {
                rgblight_setrgb_at(0, 0, 0, 4);
}


void matrix_init_user(void) {
        rgblight_enable_noeeprom();
}


void matrix_scan_user(void) {
        LEADER_DICTIONARY() {
                leading = false;
                leader_end();

                SEQ_FOUR_KEYS(KC_C, KC_S, KC_A, KC_G) {
                      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("g"))));
                }

                SEQ_FOUR_KEYS(KC_C, KC_S, KC_A, KC_T) {
                      SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("t"))));
                }
        }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

        switch (keycode) {
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

uint32_t layer_state_set_user(uint32_t state) {
        // icekeys_led_off();

        uint8_t layer = biton32(state);
        switch (layer) {
        case _SYMB:
                isDefaultLayer = _SYMB;
                rgblight_setrgb_at(130, 0, 0, 1);
                break;
        case _FUNC:
                isDefaultLayer = _FUNC;
                rgblight_setrgb_at(130, 0, 0, 6);
                break;
        case _NUMS:
                isDefaultLayer = _NUMS;
                rgblight_setrgb_at(130, 255, 130, 0);
                break;
        case _NVMD:
                isDefaultLayer = _NVMD;
                rgblight_setrgb_at(130, 255, 130, 7);
                break;
        // case 2:
        // break;
        default:
                isDefaultLayer = _BASE;
                rgblight_setrgb_at(0, 0, 0, 0);
                rgblight_setrgb_at(0, 0, 0, 1);
                rgblight_setrgb_at(0, 0, 0, 6);
                rgblight_setrgb_at(0, 0, 0, 7);
                break;
        }

        return state;
}
