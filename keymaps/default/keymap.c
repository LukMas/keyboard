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
      _BASE = 0
};

//,
led_config_t g_led_config = { {
  // Key Matrix to LED Index
   {   0, 1, 2,  6,  7,  8 }, 
   {   3, 4, 5,  9, 10, 11 }
}, {
  // LED Index to Physical Position
   { 0, 0 },  { 45, 0 },  { 90, 0 },  { 134, 0 },  { 180, 0 },  { 224, 0 }, 
   { 0, 64 }, { 45, 64 }, { 90, 64 }, { 134, 64 }, { 180, 64 }, { 224, 64 }
}, {
  // LED Index to Flag
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
} };


uint8_t isDefaultLayer = _BASE;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [_BASE] = LAYOUT( 
               KC_Q,          KC_W,     KC_E,      KC_R,      KC_T,     KC_Y,\
               KC_A,          KC_S,     KC_D,      KC_F,      KC_G,     KC_H  
                      )
};
