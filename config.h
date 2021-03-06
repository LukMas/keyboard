/*
   Copyright 2018 REPLACE_WITH_YOUR_NAME

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

#define MASTER_RIGHT


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Luca Masera
#define PRODUCT         Snowflake
#define DESCRIPTION     Snowflake keyboard


/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 6


/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 * yes
 */
//F4,
#define MATRIX_ROW_PINS {F4, F5}
// #define MATRIX_COL_PINS {F1, F4, F5, F6, F7, B6, B5}
// #define MATRIX_COL_PINS {F6, F7, B6, B5, F1, F4, F5}
#define MATRIX_COL_PINS    {B5, B4, E6}
//#define MATRIX_ROW_PINS_RIGHT {F4, F5}
//#define MATRIX_COL_PINS_RIGHT {E6, B4, B5}

#define UNUSED_PINS

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#define RGB_DI_PIN D7
#define DRIVER_LED_TOTAL 12
//#define RGBLED_NUM 12
#define RGBLED_SPLIT { 6, 6 }

#define TAPPING_TERM 200
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 1500
#define TAPPING_TOGGLE 3

// #define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 3


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST


#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
 #   define DISABLE_RGB_MATRIX_ALPHAS_MODS
 #   define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
 #   define DISABLE_RGB_MATRIX_BREATHING
 #   define DISABLE_RGB_MATRIX_CYCLE_ALL
 #   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
 #   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
 #   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
 #   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
 #   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
 #   define DISABLE_RGB_MATRIX_DUAL_BEACON
 #   define DISABLE_RGB_MATRIX_RAINBOW_BEACON
 #   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
 #   define DISABLE_RGB_MATRIX_RAINDROPS
 #   define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #   define DISABLE_RGB_MATRIX_TYPING_HEATMAP
 #   define DISABLE_RGB_MATRIX_DIGITAL_RAIN
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
 #   define DISABLE_RGB_MATRIX_SPLASH
 #   define DISABLE_RGB_MATRIX_MULTISPLASH
 #   define DISABLE_RGB_MATRIX_SOLID_SPLASH
 #   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

/* number of backlight levels */


/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
/*#define IS_COMMAND() ( \
                keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
                )
*/
/* control how magic key switches layers */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM false

/* override magic key keymap */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM
//#define MAGIC_KEY_HELP1          H
//#define MAGIC_KEY_HELP2          SLASH
//#define MAGIC_KEY_DEBUG          D
//#define MAGIC_KEY_DEBUG_MATRIX   X
//#define MAGIC_KEY_DEBUG_KBD      K
//#define MAGIC_KEY_DEBUG_MOUSE    M
//#define MAGIC_KEY_VERSION        V
//#define MAGIC_KEY_STATUS         S
//#define MAGIC_KEY_CONSOLE        C
//#define MAGIC_KEY_LAYER0_ALT1    ESC
//#define MAGIC_KEY_LAYER0_ALT2    GRAVE
//#define MAGIC_KEY_LAYER0         0
//#define MAGIC_KEY_LAYER1         1
//#define MAGIC_KEY_LAYER2         2
//#define MAGIC_KEY_LAYER3         3
//#define MAGIC_KEY_LAYER4         4
//#define MAGIC_KEY_LAYER5         5
//#define MAGIC_KEY_LAYER6         6
//#define MAGIC_KEY_LAYER7         7
//#define MAGIC_KEY_LAYER8         8
//#define MAGIC_KEY_LAYER9         9
//#define MAGIC_KEY_BOOTLOADER     PAUSE
//#define MAGIC_KEY_LOCK           CAPS
//#define MAGIC_KEY_EEPROM         E
//#define MAGIC_KEY_NKRO           N
//#define MAGIC_KEY_SLEEP_LED      Z

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
 */
//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
 */
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 1

/*
 * HD44780 LCD Display Configuration
 */
/*
 #define LCD_LINES           2     //< number of visible lines of the display
 #define LCD_DISP_LENGTH    16     //< visibles characters per line of the display

 #define LCD_IO_MODE      1            //< 0: memory mapped mode, 1: IO port mode

 #if LCD_IO_MODE
 #define LCD_PORT         PORTB        //< port for the LCD lines
 #define LCD_DATA0_PORT   LCD_PORT     //< port for 4bit data bit 0
 #define LCD_DATA1_PORT   LCD_PORT     //< port for 4bit data bit 1
 #define LCD_DATA2_PORT   LCD_PORT     //< port for 4bit data bit 2
 #define LCD_DATA3_PORT   LCD_PORT     //< port for 4bit data bit 3
 #define LCD_DATA0_PIN    4            //< pin for 4bit data bit 0
 #define LCD_DATA1_PIN    5            //< pin for 4bit data bit 1
 #define LCD_DATA2_PIN    6            //< pin for 4bit data bit 2
 #define LCD_DATA3_PIN    7            //< pin for 4bit data bit 3
 #define LCD_RS_PORT      LCD_PORT     //< port for RS line
 #define LCD_RS_PIN       3            //< pin  for RS line
 #define LCD_RW_PORT      LCD_PORT     //< port for RW line
 #define LCD_RW_PIN       2            //< pin  for RW line
 #define LCD_E_PORT       LCD_PORT     //< port for Enable line
 #define LCD_E_PIN        1            //< pin  for Enable lineyes
 #endif
 */
