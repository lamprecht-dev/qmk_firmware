
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
#define SET_INSIDE_KEYS(hsv) \
    {12, 8, hsv}, \
    {22, 3, hsv}, \
    {27, 3, hsv}, \
    {32, 5, hsv}, \
    {35+12, 8, hsv}, \
    {35+22, 3, hsv}, \
    {35+27, 3, hsv}, \
    {35+32, 5, hsv}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
     _GAMING,
    _L2,
    _L3,
    _L4,
    _QWERTY2,
    _FKEYS
};

enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE,
    KC_MY_MUTE,
    KC_HARD_ESC,
    KC_BASE,
    KC_MAKEBASE1,
    KC_MAKEBASE2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |  ;:  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   P  | ENT  |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * |  alt |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  /?  |  GUI |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | fkeys| CAPSL|      |  SPC | / CTRL /       \ SFT  \  |  L2    |  L3  |ALTGR|Context|
 *            |      |      |      |      |/       /         \      \ |       |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERTY2] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,   KC_7,   KC_8,    KC_9,    KC_0,  KC_DEL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX ,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,   KC_I,    KC_O,   KC_SCLN, KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB ,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,   KC_K,    KC_L,   KC_P,     KC_ENT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  OSM(MOD_LALT),KC_Z,KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  KC_D_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_LGUI),
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
         MO(_FKEYS), XXXXXXX, XXXXXXX , KC_SPC, OSM(MOD_LCTL), OSM(MOD_RSFT), TO(_L2),  TO(_L3), OSM(MOD_RALT), KC_APP
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
  [_QWERTY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,   KC_7,   KC_8,    KC_9,    KC_0,  KC_DEL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX ,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,   KC_I,    KC_O,   KC_SCLN, KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB ,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,   KC_K,    KC_L,   KC_P,     KC_ENT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LALT, KC_Z,KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  KC_D_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
          MO(_FKEYS), XXXXXXX, XXXXXXX , KC_SPC, KC_LCTL, KC_RSFT, TO(_L2),  TO(_L3), KC_RALT, KC_APP
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * L2 | Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   <  |   >  |   !  |   @  |   ?  |                    |   &  |   _  |   [  |   ]  |  "   | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   %  |   -  |   +  |   =  |   #  |-------.    ,-------|   |  |   :  |   (  |   )  |  '   | ENT  |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * |  ALT |   ~  |   /  |   *  |   \  |   `  |-------|    |-------|   ^  |   $  |   {  |   }  |  L3  |  GUI |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | fkeys |      |  SPC |  L1  |/ CTL   /       \ SFT  \  |  L4   |  L3  |ALTGR|Context|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 * ;:'",<.>/?
 */
[_L2] = LAYOUT(
    KC_HARD_ESC, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
    _______, KC_LABK, KC_RABK, KC_EXLM, KC_AT  , KC_QUES,                   KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_DQUO, _______,
    _______, KC_PERC, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                   KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUOT, _______,
    KC_LALT, KC_TILD, KC_SLSH, KC_ASTR, KC_BSLS, KC_GRV , _______, _______, KC_CIRC, KC_DLR , KC_LCBR, KC_RCBR, TO(_L3), KC_LGUI,
                      _______, XXXXXXX, KC_SPC , KC_BASE, KC_LCTL, KC_RSFT, TO(_L4), TO(_L3), KC_RALT, _______

    ),

/* L4 / Num and Media
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |      |                    |      |      |   /  |   *  |   -  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MPREV |MPAUSE|MNEXT |Speakr|                    |      |   7  |   8  |   9  |   +  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB | B TAB|      |RUNVCM|RSTVCM| Mic  |-------.    ,-------|      |   4  |   5  |   6  |   =  |  ENT |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * | ALT  |      |      |      |      |      |-------|    |-------|  SPC |   1  |   2  |   3  |  L3  | GUI  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | fkeys|       |  SPC |  L1  | / CTL  /       \ SFT  \  |  L2  |  L3  |   0  |   .  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_L4] = LAYOUT(
    KC_HARD_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS, _______,
    _______, XXXXXXX, KC_MPRV, KC_MEDIA_PLAY_PAUSE, KC_MNXT, XXXXXXX,       XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PLUS , _______,
    _______, LSFT(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_EQUAL, _______,
    KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_SPC, KC_KP_1, KC_KP_2, KC_KP_3, TO(_L3), KC_LGUI,
                      _______, XXXXXXX, KC_SPC , KC_BASE, KC_LCTL, KC_RSFT, TO(_L2), _______, KC_KP_0, KC_DOT
    ),
/* L3 / Navigation
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |      |                    |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |                    |  PUP | HOME |  END |PrintS|  INS | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |      |      |      |      |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT| PAUSE|  ENT |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * | Alt  |      |      |      |      |      |-------|    |-------| PDown|      |      |      |      | GUI  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | fkeys|      |  SPC |  L1  | / CTL  /       \ SFT  \  |  L2  |      | ALTGR|Context|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_L3] = LAYOUT(
    KC_HARD_ESC, XXXXXXX,      XXXXXXX,        XXXXXXX, KC_MAKEBASE1, KC_MAKEBASE2,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    KC_CAPS_LOCK, XXXXXXX,      XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, KC_HOME, KC_END , KC_PSCR, KC_INS , _______,
    _______, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP , KC_RIGHT, KC_PAUSE, _______,
    KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI,
                                      _______, XXXXXXX, KC_SPC, KC_BASE, KC_LCTL, KC_RSFT, TO(_L2), XXXXXXX, KC_RALT, _______
     ),


/*
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |       |      | /      /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
/*[] = LAYOUT(*/
/*    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX*/
/**/
/*    ),*/
/*
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |       |      | /      /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FKEYS] = LAYOUT(
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_RED),
  SET_NUMROW(HSV_RED),
  SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_PINK),
  SET_NUMROW(HSV_PINK),
  SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_TEAL),
  SET_NUMROW(HSV_TEAL),
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_BLUE),
  SET_NUMROW(HSV_BLUE),
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_PURPLE),
  SET_NUMROW(HSV_PURPLE),
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_ORANGE),
  SET_NUMROW(HSV_ORANGE),
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_INSIDE_KEYS(HSV_GREEN),
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights,
	layer_switcher_lights,  // Overrides other layers
	layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state,_QWERTY));


	rgblight_set_layer_state(1, layer_state_cmp(state, _L2));
	rgblight_set_layer_state(2, layer_state_cmp(state, _L3));
	rgblight_set_layer_state(4, layer_state_cmp(state, _L4));
	rgblight_set_layer_state(5, layer_state_cmp(state, _GAMING));
	rgblight_set_layer_state(6, layer_state_cmp(state, _QWERTY2));

    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

bool current_base_osm = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MY_MUTE:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_F13);
            }
            else{
                unregister_code(KC_LALT);
                unregister_code(KC_F13);
            }
            break;
        case KC_HARD_ESC:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                layer_move(_QWERTY);
            }
            else{
                return false;
            }
            break;
        case KC_BASE:
            if(current_base_osm){
                layer_move(_QWERTY2);
            }
            else{
                layer_move(_QWERTY);
             }
            return false;
        case KC_MAKEBASE1:
            current_base_osm = true;
            layer_move(_QWERTY2);
            return false;
        case KC_MAKEBASE2:
            current_base_osm = false;
            layer_move(_QWERTY);
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}

#endif
