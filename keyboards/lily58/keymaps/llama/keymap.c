 /* Copyright 2020 Naoki Katahira
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
#include <stdio.h>

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ~   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Play  |    |   M3  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,  KC_BTN3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        LOWER,   KC_LGUI, KC_LALT, KC_SPC,           KC_ENT,  KC_BSPC, KC_RGUI, RAISE
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |Print |Scroll|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |Insert| Home |PG UP |      |      |                    |      |  [   |   ]  |  \   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL | Del  | End  |PG DW |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|  M1   |    |  M2   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|   =  |      |      |      |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSCR, KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_INS,  KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, XXXXXXX,
  _______, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______,               _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______,               _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______,               _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

// Animation params
#define FRAME_DURATION 333 // How long each frame should last in ms

// Animation vars
uint32_t timer = 0;
uint8_t current_frame = 0;

// Art generated with https://www.pixilart.com/
// Code generated with https://joric.github.io/qle/
// https://github.com/ALameLlama/keyboard/blob/master/resources/llama.gif
static void render_animation(void) {
    static const char frame_1 [] PROGMEM = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,240,224,224,224,224,240,192,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,190,231,155,101,125,125, 93, 93,125, 37,195,190,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,195,195,195,195,195,195,195,195,252,252,252,252,  0,  0,  0,  0,255,255,255,255, 60, 60, 60, 60,192,192,192,192, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0,252,252,252,252,195,195,195,195,195,195,195,195,252,252,252,252,  0,  0, 
        0,  0, 28,196,240,248,252,252,252,252,252,255,255,255,255,255,255,255,255,255,255,127, 26,  0,  0,  0,255,255,255,255,192,192,192,192,192,192,192,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,192,192,192,192,192,192,192,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0, 
        0,  0,  0,  0,  1, 11, 11, 11,  3, 27,  3,  3,  3,  3, 11, 11, 11,  3, 27,  3,  1,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,
    };
    static const char frame_2 [] PROGMEM = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,240,224,224,224,224,240,192,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,190,231,155,101,125,125, 93, 93,125, 37,195,190,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,195,195,195,195,195,195,195,195,252,252,252,252,  0,  0,  0,  0,255,255,255,255, 60, 60, 60, 60,192,192,192,192, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0,252,252,252,252,195,195,195,195,195,195,195,195,252,252,252,252,  0,  0, 
        0,  0, 28,196,240,248,252,252,252,252,252,254,255,255,255,255,255,255,255,255,255,127, 27,  0,  0,  0,255,255,255,255,192,192,192,192,192,192,192,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,192,192,192,192,192,192,192,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0, 
        0,  0,  0,  0,  1,  3, 27, 27,  3, 27,  3,  3,  3,  3,  3, 27, 27,  3, 27,  3,  1,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,
    };
    static const char frame_3 [] PROGMEM = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,240,224,224,224,224,240,192,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,190,231,155,101,125,125, 93, 93,125, 37,195,190,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,195,195,195,195,195,195,195,195,252,252,252,252,  0,  0,  0,  0,255,255,255,255, 60, 60, 60, 60,192,192,192,192, 60, 60, 60, 60,255,255,255,255,  0,  0,  0,  0,252,252,252,252,195,195,195,195,195,195,195,195,252,252,252,252,  0,  0, 
        0,  0, 28,196,240,248,252,252,252,252,252,252,254,255,255,255,255,255,255,255,255,127, 27,  1,  0,  0,255,255,255,255,192,192,192,192,192,192,192,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,192,192,192,192,192,192,192,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  3,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0, 
        0,  0,  0,  0,  1,  3, 27, 27,  3, 11,  3,  3,  3,  3,  3, 27, 27,  3, 11,  3,  1,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,
    };

    // Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 2112)
    // const int animation_bitmap_allArray_LEN = 4;
    const char* animation_bitmap_allArray[4] = {
        frame_1,
        frame_2,
        frame_3,
        frame_2
    };

    uint16_t animation_bitmap_frame_sizes[4] = {
        sizeof(frame_1),
        sizeof(frame_2),
        sizeof(frame_3),
        sizeof(frame_2)
    };

    if (timer_elapsed(timer) > FRAME_DURATION) {
        timer = timer_read();

        current_frame = (current_frame + 1) % (sizeof(animation_bitmap_allArray) / sizeof(animation_bitmap_allArray[0]));

        oled_write_raw_P(animation_bitmap_allArray[current_frame], animation_bitmap_frame_sizes[current_frame]);
    }
}

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
            record->event.key.row, record->event.key.col,
            keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
}

const char *read_keylog(void) {
    return keylog_str;
}

const char *read_keylogs(void) {
    return keylogs_str;
}

#define OLED_SCREENSAVER_TIMEOUT 30000

bool oled_task_user(void) {
	if (last_input_activity_elapsed() > OLED_SCREENSAVER_TIMEOUT) {
		oled_off();
	} else {
        if (is_keyboard_master()) {
            // Host Keyboard Layer Status
            oled_write_P(PSTR("Layer: "), false);

            switch (get_highest_layer(layer_state)) {
                case _QWERTY:
                    oled_write_ln_P(PSTR("Default"), false);
                    break;
                case _RAISE:
                    oled_write_ln_P(PSTR("Raise"), false);
                    break;
                case _LOWER:
                    oled_write_ln_P(PSTR("Lower"), false);
                    break;
                case _ADJUST:
                    oled_write_ln_P(PSTR("Adjust"), false);
                    break;
                default:
                    oled_write_ln_P(PSTR("Undefined"), false);
            }

            oled_write_ln(read_keylog(), false);
            oled_write_ln(read_keylogs(), false);
        } else {
            render_animation();
        }
    }
    
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
    // set_timelog();
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool handle_master_encoder(bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            break;
        case _LOWER:
            tap_code(clockwise ? KC_MS_R : KC_MS_L);
            break;
        case _QWERTY:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
        case _ADJUST:
        default:
            break;
    }

    return true;
}

bool handle_slave_encoder(bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            break;
        case _LOWER:
            tap_code(clockwise ? KC_MS_D : KC_MS_U);
            break;
        case _QWERTY:
            tap_code(clockwise ? KC_WH_D : KC_WH_U);
            break;
        case _ADJUST:
        default:
            break;
    }

    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    bool handled = false;

    switch (index) {
        case 0:
            handled = handle_master_encoder(clockwise);
            break;
        case 1:
            handled = handle_slave_encoder(clockwise);
            break;
        default:
            break;
    }

    return handled;
}

#endif // ENCODER_ENABLE
