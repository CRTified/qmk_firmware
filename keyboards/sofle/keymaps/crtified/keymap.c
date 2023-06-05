
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}


#if 0
  // TEMPLATE
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       XXXXXXX,         XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   XXXXXXX,   KC_LGUI,  _______,        KC_SPC,           KC_ENT,            MO(4),   KC_RALT,   XXXXXXX,  XXXXXXX
    //

    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
#endif


enum sofle_layers {
    _DEFAULTS = 0,
    _BASE = 0,
    _RISE,
    _FKEY,
    _CONF,
    _TBOI,
};

static const char *get_layer_name(int layer)
{
  switch(layer) {
  case _BASE: return PSTR("Base");
  case _RISE: return PSTR("Rise");
  case _FKEY: return PSTR("FKey");
  case _CONF: return PSTR("Conf");
  case _TBOI: return PSTR("TBoI");
  default: return PSTR("Undef");
  }
};

    //    +-----+
    //    |_BASE|
    //    ++---++
    //     |   |
    //     |   |
    // _FKEY   _RISE
    //    |      |
    //    +--+---+
    //       |        +-----+
    //     _CONF----->|_TBOI|
    //                +-----+

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                             KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,   KC_BSPC,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                             KC_H,      KC_J,      KC_K,      KC_L,   KC_SCLN,   KC_QUOT,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,       KC_MUTE,         KC_MPLY,             KC_N,      KC_M,   KC_COMM,    KC_DOT,   KC_SLSH,    KC_ESC,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           KC_LCTL,   KC_LALT,   KC_LGUI, MO(_FKEY),       KC_SPC,           KC_ENT,        MO(_RISE),   KC_RALT,    KC_DOT,  KC_RCTL
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_FKEY] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/       KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,                                            KC_F7,     KC_F8,     KC_F9,    KC_F10,    KC_F11,    KC_F12,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_F13,    KC_F14,    KC_F15,    KC_F16,    KC_F17,    KC_F18,                                           KC_F19,    KC_F20,    KC_F21,    KC_F22,    KC_F23,    KC_F24,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,   XXXXXXX,   XXXXXXX,   KC_BTN1,   KC_MS_U,   KC_BTN2,                                          XXXXXXX,     KC_UP,   KC_PSCR,    KC_INS,   KC_HOME,   KC_PGUP,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   KC_MS_L,   KC_MS_D,   KC_MS_R,       KC_MUTE,         XXXXXXX,          KC_LEFT,   KC_DOWN,  KC_RIGHT,    KC_DEL,    KC_END,   KC_PGDN,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           KC_LCTL,   KC_LALT,   KC_LGUI,   _______,       KC_SPC,           KC_ENT,        MO(_CONF),   KC_RALT,   XXXXXXX, KC_RCTL
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_RISE] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,   KC_EXLM,     KC_AT,   KC_HASH,    KC_DLR,   KC_PERC,                                          KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_BSPC,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          KC_MINS,    KC_EQL,   KC_LBRC,   KC_RBRC,   KC_BSLS,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       KC_MUTE,         XXXXXXX,          KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   KC_PIPE,   KC_TILD,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   KC_LALT,   KC_LGUI, MO(_CONF),       KC_SPC,           KC_ENT,          XXXXXXX,   KC_RALT,   XXXXXXX,  XXXXXXX
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_CONF] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     RGB_TOG,   RGB_HUI,   RGB_SAI,   RGB_VAI,   RGB_SPI,   XXXXXXX,                                        DF(_TBOI),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     RGB_MOD,   RGB_HUD,   RGB_SAD,   RGB_VAD,   RGB_SPD,   XXXXXXX,       KC_MUTE,         XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   XXXXXXX,   KC_LGUI,   XXXXXXX,       KC_SPC,           KC_ENT,          XXXXXXX,   KC_RALT,   XXXXXXX,  XXXXXXX
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_TBOI] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, DF(_BASE),
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,      KC_Q,      KC_W,      KC_E,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,     KC_UP,   XXXXXXX,      KC_P,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     XXXXXXX,      KC_A,      KC_S,      KC_D,      KC_F,   XXXXXXX,                                          XXXXXXX,   KC_LEFT,   KC_DOWN,  KC_RIGHT,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       KC_MUTE,         XXXXXXX,          XXXXXXX,      KC_M,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_ESC,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_TAB,       KC_SPC,           KC_ENT,          XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),
};

#ifdef RGBLIGHT_ENABLE
#endif

#ifdef OLED_ENABLE


static const char PROGMEM icons[][160] = { // 32x40
  [_BASE] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0xc0, 0x80, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x38, 0x38, 0x39, 0xbf, 0xbf, 0xbf, 0xbc, 0x38, 0x38, 0x38,
    0x3b, 0x3f, 0x1f, 0x7e, 0xfe, 0xff, 0xcf, 0x03, 0x80, 0xe0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x1c, 0x1c, 0x9c, 0xdc, 0xfc, 0xfc, 0x7f, 0xff, 0xf7, 0xc1, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc1, 0xf7, 0xff, 0x7f, 0x1f, 0x1f, 0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x03, 0x00, 0xc0, 0xf1, 0xff, 0x7f, 0x3f, 0xfe, 0xfe, 0xee,
    0xce, 0x0e, 0x0e, 0x0f, 0x3f, 0xff, 0xff, 0xee, 0x0e, 0x0e, 0x0e, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  },
  [_RISE] = {0},
  [_FKEY] = {0},
  [_CONF] = {0},
  [_TBOI] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x0c, 0x0c,
    0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0xf8, 0x1e, 0x07, 0x81, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0xc0, 0xc0, 0x81, 0x07, 0x1e, 0xf8, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x0f, 0x3c, 0x70, 0xc7, 0x8e, 0x0e, 0x0f, 0x0f, 0x07, 0x00, 0x1c, 0x34, 0x34,
    0x34, 0x34, 0x1c, 0x00, 0x07, 0x0e, 0x0e, 0x0f, 0x8f, 0xc7, 0x70, 0x3c, 0x0f, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0xfb, 0x0f, 0x06, 0xe6, 0x0c, 0x0c, 0x0c, 0x0c,
    0x0c, 0x0c, 0x0c, 0x0c, 0xe6, 0x06, 0x0f, 0xfb, 0xf1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1c, 0x18, 0x18, 0x0f,
    0x0f, 0x18, 0x18, 0x1c, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  },
};

static const char *getIcon(int layer){
  switch(layer) {
  case _BASE:
  case _RISE:
  case _FKEY:
  case _CONF:
  case _TBOI: return icons[layer];
  default: return icons[_BASE];
  }
};


static void print_slave(void) {
  oled_write_raw_P(getIcon(get_highest_layer(layer_state)), 160);
}

static void print_master(void) {
    oled_write_ln_P(get_layer_name(get_highest_layer(default_layer_state)), false);
    // Print current layer
    oled_write_ln_P(PSTR("\nLAYER"), false);
    oled_write_ln_P(get_layer_name(get_highest_layer(layer_state)), false);
    oled_write_ln_P(PSTR("\n"), false);

    oled_write_raw_P(getIcon(get_highest_layer(default_layer_state)), 160);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_master();
    } else {
        print_slave();
    }

    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#ifdef ENCODER_ENABLE
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_RISE] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
  [_FKEY] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
  [_CONF] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
  [_TBOI] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif
#endif
