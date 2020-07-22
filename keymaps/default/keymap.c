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
        _MEDI,  // media keys
        _NAVI   // navigation keys
};

enum CustomKeycodes {
        W_LS = SAFE_RANGE,
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
        R_SQRB_ALT,
        RST_KEYB,
        ESC_GUI
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

uint8_t isDefaultLayer = _BASE;
const uint8_t MODS_TAP_COUNT = 2;

//#define TO_FUNC         TT(_FUNC)
//#define TO_SYMB         TT(_SYMB)
#define TO_FUNC         OSL(_FUNC)
#define TO_SYMB         OSL(_SYMB)
#define NVMD_TAB        LT(_MEDI, KC_TAB)
#define TD_L_PT_CR      TD(L_PRT_CTRL)
#define TD_R_PT_CR      TD(R_PRT_CTRL)
#define TD_L_BR_SH      TD(L_BRK_SHIFT)
#define TD_R_BR_SH      TD(R_BRK_SHIFT)
#define TD_L_SQ_AL      TD(L_SQRB_ALT)
#define TD_R_SQ_AL      TD(R_SQRB_ALT)
#define TD_RST_KYB      TD(RST_KEYB)
#define TD_ESC_GUI      TD(ESC_GUI)
#define NAVI_INS        LT(_NAVI, KC_INS)
#define NAVI_APP        LT(_NAVI, KC_APP)
#define TO_NAVI         MO(_NAVI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT(
                 NVMD_TAB,     KC_Q,     KC_W,      KC_E,     KC_R,     KC_T,            /**/  \
               TD_L_PT_CR,     KC_A,     KC_S,      KC_D,     KC_F,     KC_G,            /**/  \
               TD_L_BR_SH,     KC_Z,     KC_X,      KC_C,     KC_V,     KC_B,            /**/  \
               TD_L_SQ_AL,                       TO_NAVI,  TO_FUNC,   KC_SPC,   KC_DEL,  /**/  \
                                                                                    KC_Y,      KC_U,     KC_I,     KC_O,     KC_P,    TD_ESC_GUI,     \
                                                                                    KC_H,      KC_J,     KC_K,     KC_L,     KC_SCLN, TD_R_PT_CR,     \
                                                                                    KC_N,      KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, TD_R_BR_SH,     \
                                                                        KC_BSPC,    KC_ENT,    TO_SYMB,  TO_NAVI,                     TD_R_SQ_AL      
        ),
        [_SYMB] = LAYOUT(
                   KC_TAB,    KC_NO,    KC_NO,    KC_GRV,  KC_PIPE,   KC_EQL,            /**/  \
                  KC_LCTL,     KC_1,     KC_2,      KC_3,     KC_4,     KC_5,            /**/  \
                  KC_LSFT,    KC_NO,   KC_DLR,   KC_LCBR,  KC_RCBR,   KC_APP,            /**/  \
                  KC_LALT,                       TO_NAVI,  KC_LALT,  KC_LSFT,  KC_RCTL,  /**/  \
                                                                                    KC_MINS,   KC_AMPR,  KC_QUOT,  KC_NO,    KC_NO,   KC_ESC,      \
                                                                                    KC_6,      KC_7,     KC_8,     KC_9,     KC_0,    KC_RCTL,     \
                                                                                    KC_INS,    KC_NO,    KC_NO,    KC_NO,    KC_BSLS, KC_RSFT,     \
                                                                        KC_NO,      KC_NO,     KC_TRNS,  KC_TRNS,                     KC_ALGR    
        ),
        [_FUNC] = LAYOUT(
                   KC_TAB,    KC_NO,   KC_F10,    KC_F11,   KC_F12,    KC_NO,            /**/  \
                  KC_LCTL,    KC_NO,    KC_F7,     KC_F8,    KC_F9,    KC_NO,            /**/  \
                  KC_LSFT,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,            /**/  \
                  KC_LALT,                       KC_TRNS,  KC_TRNS,    KC_NO,    KC_NO,  /**/  \
                                                                                    KC_NO,     KC_F4,    KC_F5,    KC_F6,    KC_NO,   KC_ESC,      \
                                                                                    KC_NO,     KC_F1,    KC_F2,    KC_F3,    KC_NO,   KC_RCTL,     \
                                                                                    KC_NO,     KC_DLR,   KC_LPRN,  KC_RPRN,  KC_NO,   KC_RSFT,     \
                                                                        KC_LCTL,    KC_LSFT,   KC_LALT,  TO_NAVI,                     KC_ALGR    
        ),
        [_MEDI] = LAYOUT(
                  KC_TRNS,    KC_NO,    KC_NO,   KC_VOLU,    KC_NO,    KC_NO,            /**/ \
                    KC_NO,    KC_NO,  KC_MPRV,   KC_VOLD,  KC_MNXT,    KC_NO,            /**/ \
                  KC_WAKE,    KC_NO,    KC_NO,   KC_MUTE,    KC_NO,    KC_NO,            /**/ \
                  KC_SLEP,                         KC_NO,     W_LS,     W_LD,     GO_L,  /**/ \
                                                                                    KC_NO,     KC_NO,    KC_WH_U,  KC_NO,    KC_NO,   TD_RST_KYB, \
                                                                                    KC_NO,     KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_NO,   KC_NO,      \
                                                                                    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,      \
                                                                        GO_R,       W_RD,      W_RS,     KC_NO,                       KC_MPLY    
        ),
        [_NAVI] = LAYOUT(
                  KC_TAB,     KC_NO,    KC_NO,   KC_PGUP,    KC_NO,    KC_NO,            /**/ \
                  KC_LCTL,    KC_NO,  KC_HOME,   KC_PGDN,   KC_END,    KC_NO,            /**/ \
                  KC_LSFT,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,            /**/ \
                  KC_LALT,                       KC_TRNS,  KC_LALT,  KC_LSFT,  KC_LCTL,  /**/ \
                                                                                    KC_NO,     KC_NO,    KC_UP,    KC_NO,    KC_NO,   KC_ESC,    \
                                                                                    KC_NO,     KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,   KC_RCTL,   \
                                                                                    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_RSFT,   \
                                                                        KC_LCTL,    KC_LSFT,   KC_LALT,  KC_TRNS,                     KC_ALGR
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


int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
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


//instanalize an instance of 'tap' for the 'x' tap dance.
static tap EscOrGui_state = {
  .is_press_action = true,
  .state = 0
};

void dance_EscGui_finished (qk_tap_dance_state_t *state, void *user_data) {
  EscOrGui_state.state = cur_dance(state);
  switch (EscOrGui_state.state) {
    case SINGLE_TAP:  register_code(KC_ESC); break;
    case DOUBLE_TAP:  register_code(KC_LGUI); break;
    case DOUBLE_HOLD:  register_code(KC_LGUI); rgblight_setrgb_at(150, 150, 150, 0); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void dance_EscGui_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (EscOrGui_state.state) {
    case SINGLE_TAP:  unregister_code(KC_ESC); break;
    case DOUBLE_TAP:  unregister_code(KC_LGUI); break;
    case DOUBLE_HOLD:  unregister_code(KC_LGUI); rgblight_setrgb_at(0, 0, 0, 0); break;
  }
  EscOrGui_state.state = 0;
}

void dance_ResetKeyboard(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 5) {
    uint8_t ledId = 0;
    while (ledId< 8) {
      rgblight_setrgb_at(0, 0, 0, ledId);
      ledId++;
    }
    
    while (ledId > 0) {
      ledId--;
      rgblight_setrgb_at(80, 80, 80, ledId);    
      wait_ms(20);
    }
    
    wait_ms(100);
      
    while (ledId < 8) {
      rgblight_setrgb_at(0, 0, 0, ledId);
      wait_ms(20);
      ledId++;        
    }
    
    reset_keyboard();
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [L_PRT_CTRL]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_l_ctrl_finished, dance_l_ctrl_reset),
    [R_PRT_CTRL]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_ctrl_finished, dance_r_ctrl_reset),
    [L_BRK_SHIFT]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_l_shift_finished, dance_l_shift_reset),
    [R_BRK_SHIFT]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_shift_finished, dance_r_shift_reset),
    [L_SQRB_ALT]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_l_alt_finished, dance_l_alt_reset),
    [R_SQRB_ALT]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_alt_finished, dance_r_alt_reset),
    [ESC_GUI]      = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_EscGui_finished, dance_EscGui_reset),
    [RST_KEYB]     = ACTION_TAP_DANCE_FN (dance_ResetKeyboard)
};


void matrix_init_user(void) {
        rgblight_enable_noeeprom();
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

        switch (keycode) {
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
                
        case _MEDI: 
                isDefaultLayer = _MEDI;
                rgblight_setrgb_at(130, 255, 130, 0);
                break;
                
        case _NAVI:
                isDefaultLayer = _NAVI;
                rgblight_setrgb_at(130, 255, 130, 7);
                break;
                
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

void oneshot_layer_changed_user(uint8_t layerId) {
  if (layerId) {
      uint8_t layer = biton32(layerId);
      
      if (layer == _NAVI) {
          isDefaultLayer = _NAVI;
          rgblight_setrgb_at(130, 255, 130, 7);
      }
      
  } else {
    isDefaultLayer = _BASE;
    rgblight_setrgb_at(0, 0, 0, 0);
    rgblight_setrgb_at(0, 0, 0, 1);
    rgblight_setrgb_at(0, 0, 0, 6);
    rgblight_setrgb_at(0, 0, 0, 7);
  }
}

