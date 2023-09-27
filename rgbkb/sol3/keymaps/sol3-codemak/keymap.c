/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │  RGB │ ADJ  │      │ DEL  │  │ Enter│      │  FN  │ Left │ Down │ Up   │Right │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│                │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│
 * └──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _MAIN,
    _XLnMS,
    _NUMPAD,
    _SETTINGS,
    _QWERTY
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

#define XLnMS    TG(_XLnMS)
#define SETTING  TG(_SETTINGS)
#define TEMPSET  TT(_SETTINGS)
#define QWERTY   TG(_QWERTY)
#define NUMPS    TG(_NUMPAD)
#define MAIN     TO(_MAIN)
#define XL_NUBS  LT(_XLnMS, KC_NUBS)
#define CTRL_L   LCTL(KC_LEFT)
#define CTRL_R   LCTL(KC_RGHT)
#define CTRL_U   LCTL(KC_UP)
#define CTRL_D   LCTL(KC_DOWN)
#define CTRL_H   LCTL(KC_HOME)
#define CTRL_E   LCTL(KC_END)
#define CTRL_PU  LCTL(KC_PGUP)
#define CTRL_PD  LCTL(KC_PGDN)
//#define RGB_ADJ  LT(_ADJUST, RGB_TOG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XLnMS,                    KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC,                  KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_CAPS,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_LPRN,                  KC_RPRN, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        XL_NUBS,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    TEMPSET,                  KC_RPRN, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_PGUP, KC_PGDN, KC_SPC,  RGB_TOG, KC_LSFT, KC_ENT, KC_DEL, KC_BSPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RBRC,

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        KC_WH_D, KC_WH_U, KC_RPRN, KC_RCBR, KC_MINS,                                                       KC_WH_D, KC_WH_U, KC_RPRN, KC_LPRN, KC_MINS
    ),

    [_XLnMS] = LAYOUT(
        QK_GESC,  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   MAIN,                     _______,  KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_SCRL,
        KC_TAB,   CTRL_U, KC_UP,    CTRL_H, KC_PGUP, KC_F11,  _______,                   _______,  KC_F12, KC_HOME, KC_MS_U, KC_END,  KC_PSCR, KC_PGUP,
        CTRL_L,  KC_LEFT, KC_DOWN, KC_RGHT,  CTRL_R, CTRL_PU, _______,                   _______, KC_BRIU, KC_MS_L, KC_MS_D, KC_MS_R, KC_INS,  KC_PGDN,
        XL_NUBS, AU_TOGG,  CTRL_D,  CTRL_E, KC_PGDN, CTRL_PD, NUMPS,                     _______, KC_BRID, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, KC_NUM,
        KC_LCTL, KC_LGUI, KC_LALT, KC_PGUP, KC_PGDN, KC_SPC,  RGB_TOG, KC_LSFT, KC_BTN1, _______, KC_BTN2, KC_VOLD, KC_VOLU, KC_MUTE, KC_RGHT, KC_RBRC,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       KC_WH_D, KC_WH_U, KC_RPRN, KC_BTN3, KC_MINS
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, MAIN,                      _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_BSPC,
        _______, _______, _______, _______, _______, _______, SETTING,                   _______, _______, KC_P1,   KC_P2,   KC_P3 ,  KC_PEQL, KC_LPRN,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PENT, _______, KC_PENT, KC_P0,   KC_P0,   KC_PDOT, _______, KC_RPRN,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
    
    [_SETTINGS] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   MAIN,                      _______,  KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_SCRL,
        _______, RGB_HUI, RGB_HUD, _______, QK_BOOT, KC_F11,  _______,                   _______,  KC_F12, KC_HOME, KC_MS_U, KC_END,  KC_PSCR, KC_PGUP,
        _______, RGB_SAI, RGB_SAD, _______, RGB_RST, DM_REC1, _______,                   _______, KC_BRIU, KC_MS_L, KC_MS_D, KC_MS_R, KC_INS,  KC_PGDN,
        _______, RGB_VAI, RGB_VAD, _______, _______, DM_RSTP, QWERTY,                    _______, KC_BRID, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, KC_NUM,
        _______, RGB_SPI, RGB_SPD, _______, _______, RGB_RMOD,RGB_TOG, RGB_MOD, KC_BTN1, _______, KC_BTN2, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       KC_WH_D, KC_WH_U, _______, KC_BTN3, _______
    ),

    [_QWERTY] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    MAIN,                     KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,                  KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        XL_NUBS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TO(_XLnMS),               KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_PGUP, KC_PGDN, KC_SPC,  KC_GRV, KC_LSFT, KC_ENT, KC_DEL, KC_BSPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RBRC,

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        KC_WH_D, KC_WH_U, KC_RPRN, KC_RCBR, KC_MINS,                                                       KC_WH_D, KC_WH_U, KC_RPRN, KC_LPRN, KC_MINS
    ),
    
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _MAIN:
            oled_write_ln_P(PSTR(">Main"), false);
            oled_write_ln_P(PSTR(" XL+M"), false);
            oled_write_ln_P(PSTR(" Nums"), false);
            oled_write_ln_P(PSTR(" Sett"), false);
            oled_write_ln_P(PSTR(" QWER"), false);
            break;
        case _XLnMS:
            oled_write_ln_P(PSTR(" Main"), false);
            oled_write_ln_P(PSTR(">XL+M"), false);
            oled_write_ln_P(PSTR(" Nums"), false);
            oled_write_ln_P(PSTR(" Sett"), false);
            oled_write_ln_P(PSTR(" QWER"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR(" Main"), false);
            oled_write_ln_P(PSTR(" XL+M"), false);
            oled_write_ln_P(PSTR(">Nums"), false);
            oled_write_ln_P(PSTR(" Sett"), false);
            oled_write_ln_P(PSTR(" QWER"), false);
            break;
        case _SETTINGS:
            oled_write_ln_P(PSTR(" Main"), false);
            oled_write_ln_P(PSTR(" XL+M"), false);
            oled_write_ln_P(PSTR(" Nums"), false);
            oled_write_ln_P(PSTR(">Sett"), false);
            oled_write_ln_P(PSTR(" QWER"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR(" Main"), false);
            oled_write_ln_P(PSTR(" XL+M"), false);
            oled_write_ln_P(PSTR(" Nums"), false);
            oled_write_ln_P(PSTR(" Sett"), false);
            oled_write_ln_P(PSTR(">QWER"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _XLnMS:
                rgb_matrix_set_color(53, 0, 0, 255);
                rgb_matrix_set_color(52, 255, 0, 0);
                rgb_matrix_set_color(51, 0, 255, 0);
                rgb_matrix_set_color(50, 255, 255, 0);
                rgb_matrix_set_color(128, 0, 255, 0);
                rgb_matrix_set_color(129, 255, 0, 0);
                rgb_matrix_set_color(130, 0, 255, 0);
                rgb_matrix_set_color(55, 0, 0, 255);
                rgb_matrix_set_color(56, 255, 0, 0);
                rgb_matrix_set_color(57, 255, 0, 0);
                rgb_matrix_set_color(58, 255, 0, 0);
                rgb_matrix_set_color(59, 0, 0, 255);
                rgb_matrix_set_color(60, 255, 0, 255);
                rgb_matrix_set_color(138, 255, 255, 0);
                rgb_matrix_set_color(137, 255, 0, 0);
                rgb_matrix_set_color(136, 255, 0, 0);
                rgb_matrix_set_color(135, 255, 0, 0);
                rgb_matrix_set_color(68, 0, 255, 255);
                rgb_matrix_set_color(66, 0, 0, 255);
                rgb_matrix_set_color(65, 0, 255, 0);
                rgb_matrix_set_color(64, 255, 255, 0);
                rgb_matrix_set_color(63, 255, 0, 255);
                rgb_matrix_set_color(141, 255, 255, 0);
                rgb_matrix_set_color(142, 0, 0, 255);
                rgb_matrix_set_color(143, 0, 0, 255);
                rgb_matrix_set_color(144, 255, 0, 255);
                rgb_matrix_set_color(145, 255, 0, 255);
                rgb_matrix_set_color(155, 255, 0, 0);
                rgb_matrix_set_color(154, 255, 0, 0);
                rgb_matrix_set_color(152, 255, 0, 0);
                rgb_matrix_set_color(151, 0, 255, 0);
                rgb_matrix_set_color(150, 0, 255, 0);
                rgb_matrix_set_color(149, 255, 0, 0);
                break;
            case _NUMPAD:
                rgb_matrix_set_color(120, 255, 0, 255);
                rgb_matrix_set_color(121, 255, 255, 0);
                rgb_matrix_set_color(122, 255, 255, 0);
                rgb_matrix_set_color(123, 0, 255, 255);
                rgb_matrix_set_color(53, 0, 0, 255);
                rgb_matrix_set_color(52, 255, 0, 0);
                rgb_matrix_set_color(51, 0, 255, 0);
                rgb_matrix_set_color(50, 255, 255, 0);
                rgb_matrix_set_color(128, 0, 255, 0);
                rgb_matrix_set_color(129, 0, 255, 0);
                rgb_matrix_set_color(130, 0, 255, 0);
                rgb_matrix_set_color(131, 255, 0, 255);
                rgb_matrix_set_color(55, 0, 0, 255);
                rgb_matrix_set_color(56, 255, 0, 0);
                rgb_matrix_set_color(57, 255, 0, 0);
                rgb_matrix_set_color(58, 255, 0, 0);
                rgb_matrix_set_color(59, 0, 0, 255);
                rgb_matrix_set_color(60, 255, 0, 255);
                rgb_matrix_set_color(137, 0, 255, 0);
                rgb_matrix_set_color(136, 0, 255, 0);
                rgb_matrix_set_color(135, 0, 255, 0);
                rgb_matrix_set_color(134, 255, 0, 0);
                rgb_matrix_set_color(133, 255, 0, 255);
                rgb_matrix_set_color(68, 0, 255, 255);
                rgb_matrix_set_color(66, 0, 0, 255);
                rgb_matrix_set_color(65, 0, 255, 0);
                rgb_matrix_set_color(64, 255, 255, 0);
                rgb_matrix_set_color(63, 255, 0, 255);
                rgb_matrix_set_color(142, 0, 255, 0);
                rgb_matrix_set_color(143, 0, 255, 0);
                rgb_matrix_set_color(144, 0, 255, 0);
                rgb_matrix_set_color(145, 255, 0, 0);
                rgb_matrix_set_color(146, 0, 0, 255);
                rgb_matrix_set_color(147, 0, 0, 255);
                rgb_matrix_set_color(155, 255, 0, 0);
                rgb_matrix_set_color(154, 255, 0, 0);
                rgb_matrix_set_color(152, 255, 0, 0);
                rgb_matrix_set_color(151, 0, 255, 0);
                rgb_matrix_set_color(150, 0, 255, 0);
                rgb_matrix_set_color(149, 255, 0, 0);
                break;
            case _SETTINGS:
                rgb_matrix_set_color(53, 255, 0, 0);
                rgb_matrix_set_color(52, 255, 0, 0);
                rgb_matrix_set_color(50, 0, 255, 255);
                rgb_matrix_set_color(128, 0, 255, 0);
                rgb_matrix_set_color(129, 255, 0, 0);
                rgb_matrix_set_color(130, 0, 255, 0);
                rgb_matrix_set_color(56, 0, 255, 0);
                rgb_matrix_set_color(57, 0, 255, 0);
                rgb_matrix_set_color(59, 255, 255, 0);
                rgb_matrix_set_color(138, 255, 255, 0);
                rgb_matrix_set_color(137, 255, 0, 0);
                rgb_matrix_set_color(136, 255, 0, 0);
                rgb_matrix_set_color(135, 255, 0, 0);
                rgb_matrix_set_color(67, 0, 0, 255);
                rgb_matrix_set_color(66, 0, 0, 255);
                rgb_matrix_set_color(141, 255, 255, 0);
                rgb_matrix_set_color(142, 0, 0, 255);
                rgb_matrix_set_color(143, 0, 0, 255);
                rgb_matrix_set_color(144, 255, 0, 255);
                rgb_matrix_set_color(145, 255, 0, 255);
                rgb_matrix_set_color(70, 255, 255, 0);
                rgb_matrix_set_color(71, 255, 255, 0);
                rgb_matrix_set_color(74, 255, 0, 255);
                rgb_matrix_set_color(75, 255, 0, 255);
                rgb_matrix_set_color(76, 255, 0, 255);
                rgb_matrix_set_color(77, 255, 0, 255);
                rgb_matrix_set_color(155, 255, 0, 0);
                rgb_matrix_set_color(154, 255, 0, 0);
                rgb_matrix_set_color(152, 255, 0, 0);
                rgb_matrix_set_color(151, 0, 255, 0);
                rgb_matrix_set_color(150, 0, 255, 0);
                rgb_matrix_set_color(149, 255, 0, 0);
                break;
            default:
                break;
        }
    return false;
}