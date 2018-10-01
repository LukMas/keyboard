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


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    You
#define PRODUCT         icekeys
#define DESCRIPTION     My custom keyboard


// #undef LEADER_TIMEOUT
// #define LEADER_TIMEOUT 100
#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 1000

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { F0, F1, F2, F3 }
#define MATRIX_COL_PINS { C0, C1, C2, C3 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

//
#define TAPPING_TERM 200
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 4000
#define TAPPING_TOGGLE 2

// #define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 3


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

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
#define IS_COMMAND() ( \
                keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
                )

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
 #define LCD_E_PIN        1            //< pin  for Enable line
 #endif
 */


 #ifdef PS2_USE_USART
 /* Use remote mode instead of the default stream mode (see link) */
 // #define PS2_MOUSE_USE_REMOTE_MODE

 /* Enable the scrollwheel or scroll gesture on your mouse or touchpad */
 // #define PS2_MOUSE_ENABLE_SCROLLING

 /* Some mice will need a scroll mask to be configured. The default is 0xFF. */
 // #define PS2_MOUSE_SCROLL_MASK 0x0F


 #define PS2_CLOCK_PORT  PORTD
 #define PS2_CLOCK_PIN   PIND
 #define PS2_CLOCK_DDR   DDRD
 #define PS2_CLOCK_BIT   5
 #define PS2_DATA_PORT   PORTD
 #define PS2_DATA_PIN    PIND
 #define PS2_DATA_DDR    DDRD
 #define PS2_DATA_BIT    2

/* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
/* set DDR of CLOCK as input to be slave */
 #define PS2_USART_INIT() do {   \
                PS2_CLOCK_DDR &= ~(1<<PS2_CLOCK_BIT);   \
                PS2_DATA_DDR &= ~(1<<PS2_DATA_BIT);     \
                UCSR1C = ((1 << UMSEL10) |  \
                          (3 << UPM10)   |  \
                          (0 << USBS1)   |  \
                          (3 << UCSZ10)  |  \
                          (0 << UCPOL1));   \
                UCSR1A = 0;                 \
                UBRR1H = 0;                 \
                UBRR1L = 0;                 \
} while (0)
 #define PS2_USART_RX_INT_ON() do {  \
                UCSR1B = ((1 << RXCIE1) |       \
                          (1 << RXEN1));        \
} while (0)
 #define PS2_USART_RX_POLL_ON() do { \
                UCSR1B = (1 << RXEN1);          \
} while (0)
 #define PS2_USART_OFF() do {    \
                UCSR1C = 0;                 \
                UCSR1B &= ~((1 << RXEN1) |  \
                            (1 << TXEN1));  \
} while (0)
 #define PS2_USART_RX_READY      (UCSR1A & (1<<RXC1))
 #define PS2_USART_RX_DATA       UDR1
 #define PS2_USART_ERROR         (UCSR1A & ((1<<FE1) | (1<<DOR1) | (1<<UPE1)))
 #define PS2_USART_RX_VECT       USART1_RX_vect
 #endif
