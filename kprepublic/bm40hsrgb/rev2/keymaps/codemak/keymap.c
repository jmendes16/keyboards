/* Copyright 2020 tominabox1
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

enum layers {
  _COLEMAK,
  _FNPAD,
  _XLnMS,
  _RGBSET
};

#define XL_NUBS  LT(_XLnMS, KC_NUBS)
#define CTRL_L   LCTL(KC_LEFT)
#define CTRL_R   LCTL(KC_RGHT)
#define CTRL_U   LCTL(KC_UP)
#define CTRL_D   LCTL(KC_DOWN)
#define CTRL_H   LCTL(KC_HOME)
#define CTRL_E   LCTL(KC_END)
#define CTRL_PU  LCTL(KC_PGUP)
#define CTRL_PD  LCTL(KC_PGDN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12_1x2uC(
    LT(_RGBSET,KC_TAB),  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,      KC_O,  KC_QUOT,
    XL_NUBS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LPRN ,
    KC_LCTL, KC_LGUI, KC_LALT, TO(_FNPAD), KC_LSFT, KC_SPC,  KC_BSPC, KC_ENT,  KC_DEL, KC_MINS,   KC_RPRN
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FNPAD] = LAYOUT_ortho_4x12_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_PEQL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_DOT,    KC_7,       KC_8,   KC_9,  KC_SLSH,
    KC_BSPC, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_EQL,    KC_4,       KC_5,   KC_6,  KC_PPLS,
    KC_PENT, KC_LCTL, KC_LALT, TO(_COLEMAK),   KC_LSFT, KC_SPC,  KC_0,    KC_1,     KC_2,       KC_3, KC_MINS
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_XLnMS] = LAYOUT_ortho_4x12_1x2uC(
        KC_TAB,   CTRL_U, KC_UP,    CTRL_H, KC_PGUP, KC_F9,  KC_F12, KC_HOME, KC_MS_U, KC_END,  KC_PSCR, KC_NUM,
        CTRL_L,  KC_LEFT, KC_DOWN, KC_RGHT,  CTRL_R, CTRL_PU, KC_BRIU,  KC_MS_L, KC_MS_D, KC_MS_R, KC_INS,  KC_LBRC,
        XL_NUBS, AU_TOGG,  CTRL_D,  CTRL_E, KC_PGDN, CTRL_PD, KC_BRID,  KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, KC_RBRC,
        KC_LCTL, KC_LGUI, KC_LALT, TO(_FNPAD),  KC_LSFT, KC_SPC, KC_BTN1, KC_BTN2, KC_VOLD, KC_VOLU, KC_MUTE
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RGBSET] = LAYOUT_ortho_4x12_1x2uC(
    LT(_RGBSET,KC_TAB), QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______,  _______, _______, _______, _______,  _______, _______, _______
),

};
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING); // default effect is normally RGB_MATRIX_CYCLE_LEFT_RIGHT
    rgb_matrix_sethsv_noeeprom(213, 255, 200);  // can also delete this line and replace RGB mode with RGB_MATRIX_MULTISPLASH
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _XLnMS:
                rgb_matrix_set_color(1, 0, 0, 255);
                rgb_matrix_set_color(2, 255, 0, 0);
                rgb_matrix_set_color(3, 0, 255, 0);
                rgb_matrix_set_color(4, 255, 255, 0);
                rgb_matrix_set_color(7, 0, 255, 0);
                rgb_matrix_set_color(8, 255, 0, 0);
                rgb_matrix_set_color(9, 0, 255, 0);
                rgb_matrix_set_color(12, 0, 0, 255);
                rgb_matrix_set_color(13, 255, 0, 0);
                rgb_matrix_set_color(14, 255, 0, 0);
                rgb_matrix_set_color(15, 255, 0, 0);
                rgb_matrix_set_color(16, 0, 0, 255);
                rgb_matrix_set_color(17, 255, 0, 255);
                rgb_matrix_set_color(18, 255, 255, 0);
                rgb_matrix_set_color(19, 255, 0, 0);
                rgb_matrix_set_color(20, 255, 0, 0);
                rgb_matrix_set_color(21, 255, 0, 0);
                rgb_matrix_set_color(24, 0, 255, 255);
                rgb_matrix_set_color(26, 0, 0, 255);
                rgb_matrix_set_color(27, 0, 255, 0);
                rgb_matrix_set_color(28, 255, 255, 0);
                rgb_matrix_set_color(29, 255, 0, 255);
                rgb_matrix_set_color(30, 255, 255, 0);
                rgb_matrix_set_color(31, 0, 0, 255);
                rgb_matrix_set_color(32, 0, 0, 255);
                rgb_matrix_set_color(33, 255, 0, 255);
                rgb_matrix_set_color(34, 255, 0, 255);
                rgb_matrix_set_color(42, 255, 0, 0);
                rgb_matrix_set_color(43, 255, 0, 0);
                rgb_matrix_set_color(44, 0, 255, 0);
                rgb_matrix_set_color(45, 0, 255, 0);
                rgb_matrix_set_color(46, 255, 0, 0);
                break;
            case _RGBSET:
                rgb_matrix_set_color(0, 0, 255, 255);
                rgb_matrix_set_color(1, 0, 255, 255);
                rgb_matrix_set_color(2, 0, 255, 255);
                rgb_matrix_set_color(3, 255, 0, 0);
                rgb_matrix_set_color(4, 255, 255, 0);
                rgb_matrix_set_color(5, 255, 0, 0);
                rgb_matrix_set_color(6, 255, 0, 0);
                rgb_matrix_set_color(7, 0, 255, 0);
                rgb_matrix_set_color(8, 0, 255, 0);
                rgb_matrix_set_color(9, 0, 0, 255);
                rgb_matrix_set_color(10, 0, 0, 255);
                break;
            case _FNPAD:
                rgb_matrix_set_color(0, 0, 0, 255);
                rgb_matrix_set_color(1, 0, 0, 255);
                rgb_matrix_set_color(2, 0, 0, 255);
                rgb_matrix_set_color(3, 0, 0, 255);
                rgb_matrix_set_color(4, 0, 0, 255);
                rgb_matrix_set_color(5, 0, 0, 255);
                rgb_matrix_set_color(6, 0, 0, 255);
                rgb_matrix_set_color(7, 0, 0, 255);
                rgb_matrix_set_color(8, 255, 255, 0);
                rgb_matrix_set_color(9, 255, 0, 0);
                rgb_matrix_set_color(10, 255, 0, 0);
                rgb_matrix_set_color(11, 0, 0, 255);
                rgb_matrix_set_color(12, 255, 0, 0);
                rgb_matrix_set_color(13, 255, 255, 0);
                rgb_matrix_set_color(14, 255, 255, 0);
                rgb_matrix_set_color(15, 255, 255, 0);
                rgb_matrix_set_color(16, 255, 255, 0);
                rgb_matrix_set_color(17, 255, 255, 0);
                rgb_matrix_set_color(18, 255, 255, 0);
                rgb_matrix_set_color(19, 255, 0, 255);
                rgb_matrix_set_color(20, 0, 255, 0);
                rgb_matrix_set_color(21, 0, 255, 0);
                rgb_matrix_set_color(22, 0, 255, 0);
                rgb_matrix_set_color(23, 255, 255, 0);
                rgb_matrix_set_color(24, 255, 0, 0);
                rgb_matrix_set_color(25, 255, 255, 0);
                rgb_matrix_set_color(26, 255, 255, 0);
                rgb_matrix_set_color(27, 255, 255, 0);
                rgb_matrix_set_color(28, 255, 255, 0);
                rgb_matrix_set_color(29, 255, 255, 0);
                rgb_matrix_set_color(30, 255, 255, 0);
                rgb_matrix_set_color(31, 0, 0, 255);
                rgb_matrix_set_color(32, 0, 255, 0);
                rgb_matrix_set_color(33, 0, 255, 0);
                rgb_matrix_set_color(34, 0, 255, 0);
                rgb_matrix_set_color(35, 255, 0, 255);
                rgb_matrix_set_color(36, 255, 0, 0);
                rgb_matrix_set_color(37, 255, 0, 0);
                rgb_matrix_set_color(38, 255, 0, 0);
                rgb_matrix_set_color(39, 255, 0, 0);
                rgb_matrix_set_color(40, 255, 0, 0);
                rgb_matrix_set_color(41, 255, 0, 0);
                rgb_matrix_set_color(42, 0, 255, 0);
                rgb_matrix_set_color(43, 0, 255, 0);
                rgb_matrix_set_color(44, 0, 255, 0);
                rgb_matrix_set_color(45, 0, 255, 0);
                rgb_matrix_set_color(46, 255, 0, 255);
                break;
            case _COLEMAK:
                rgb_matrix_set_color(0, 255, 0, 0);
                rgb_matrix_set_color(3, 255, 0, 0);
                rgb_matrix_set_color(4, 255, 0, 0);
                rgb_matrix_set_color(7, 255, 0, 0);
                rgb_matrix_set_color(8, 255, 0, 0);
                rgb_matrix_set_color(11, 255, 0, 0);
                rgb_matrix_set_color(13, 255, 0, 0);
                rgb_matrix_set_color(14, 255, 0, 0);
                rgb_matrix_set_color(17, 255, 0, 0);
                rgb_matrix_set_color(18, 255, 0, 0);
                rgb_matrix_set_color(21, 255, 0, 0);
                rgb_matrix_set_color(22, 255, 0, 0);
                rgb_matrix_set_color(25, 255, 0, 0);
                rgb_matrix_set_color(26, 255, 0, 0);
                rgb_matrix_set_color(29, 255, 0, 0);
                rgb_matrix_set_color(30, 255, 0, 0);
                rgb_matrix_set_color(33, 255, 0, 0);
                rgb_matrix_set_color(34, 255, 0, 0);
                rgb_matrix_set_color(36, 255, 0, 0);
                rgb_matrix_set_color(39, 255, 0, 0);
                rgb_matrix_set_color(40, 255, 0, 0);
                rgb_matrix_set_color(42, 255, 0, 0);
                rgb_matrix_set_color(43, 255, 0, 0);
                rgb_matrix_set_color(46, 255, 0, 0);
                break;
            default:
                rgb_matrix_set_color(1, 255, 0, 0);
                rgb_matrix_set_color(3, 255, 0, 0);
                rgb_matrix_set_color(4, 255, 0, 0);
                rgb_matrix_set_color(7, 255, 0, 0);
                rgb_matrix_set_color(8, 255, 0, 0);
                rgb_matrix_set_color(11, 255, 0, 0);
                rgb_matrix_set_color(13, 255, 0, 0);
                rgb_matrix_set_color(14, 255, 0, 0);
                rgb_matrix_set_color(17, 255, 0, 0);
                rgb_matrix_set_color(18, 255, 0, 0);
                rgb_matrix_set_color(21, 255, 0, 0);
                rgb_matrix_set_color(22, 255, 0, 0);
                rgb_matrix_set_color(25, 255, 0, 0);
                rgb_matrix_set_color(26, 255, 0, 0);
                rgb_matrix_set_color(29, 255, 0, 0);
                rgb_matrix_set_color(30, 255, 0, 0);
                rgb_matrix_set_color(33, 255, 0, 0);
                rgb_matrix_set_color(34, 255, 0, 0);
                rgb_matrix_set_color(36, 255, 0, 0);
                rgb_matrix_set_color(39, 255, 0, 0);
                rgb_matrix_set_color(40, 255, 0, 0);
                rgb_matrix_set_color(42, 255, 0, 0);
                rgb_matrix_set_color(43, 255, 0, 0);
                rgb_matrix_set_color(46, 255, 0, 0);
                break;
        }
    return false;
}