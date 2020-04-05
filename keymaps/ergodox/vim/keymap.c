#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define _______ KC_TRNS
#define X_____X KC_TRNS
#define KC_ATM LGUI(LSFT(KC_P))
#define KC_ATP LGUI(LCTL(KC_P))
#define KC_GUI_GRAVE LGUI(KC_GRAVE)
#define TO_NORM TO(NORMAL_MODE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Normal mode
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * | SUPER-`|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |  TAB   |      | WORD |  END |      |      |      |           |      | YANK | UNDO |      | OPEN |  PUT |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |    ⎋   |      |      |  DEL |      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | SHIFT  |      |      |      |VISUAL| BACK |WWW_B |           |WWW_F |      |      |      |      |      | SHIFT  |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | CTRL | ALT  |SUPER |HYPER |SUPER |                                       |SUPER |      |      |  ALT | CTRL |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | HOME | END  |       | PG UP|PG DWN|
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |BACKSP| ESC  |------|       |------|ENTER |SPACE |
  *                                 |      |      |MOUSE |       |  DEL |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [NORMAL_MODE] = KEYMAP(
    // Layer 2 Left Hand
    KC_GUI_GRAVE,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
    KC_TAB,X_____X,VIM_W,  VIM_E  ,X_____X,X_____X,X_____X,
    KC_ESC,VIM_A  ,VIM_S  ,VIM_D  ,X_____X,X_____X,
    KC_LSFT,X_____X,VIM_X  ,VIM_C  ,VIM_V  ,VIM_B  ,KC_WWW_BACK,
    KC_LCTL,KC_LALT,KC_LGUI,KC_HYPR,KC_LGUI,

                                            KC_HOME,KC_END ,
                                            X_____X,
                                            KC_BSPC,  KC_ESC , MO(MOUSE),

    // Layer 2 Right Hand
                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
                              X_____X,VIM_Y  ,VIM_U  ,VIM_I  ,VIM_O  ,VIM_P  ,X_____X,
                                      KC_LEFT,KC_DOWN  ,KC_UP  ,KC_RIGHT  ,X_____X,X_____X,
                              KC_WWW_FORWARD,X_____X,X_____X,X_____X,X_____X,X_____X,KC_LSFT,
                                              KC_RGUI,X_____X,X_____X,KC_RALT,KC_RCTL,

    KC_PGUP,  KC_PGDN,
    X_____X,
    KC_DEL , KC_ENT, KC_SPC
),

  /* Insert mode
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        |   1  |   2  |   3  |   4  |   5  | ⇧⌘P  |           | PROJ |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |    ⇥   |   Q  |   W  |   E  |   R  |   T  |  {   |           |  }   |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
  * |    ⎋   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
  * |   L⇧   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   R⇧   |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |       |      |     |                                       |      |      |      |      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | HOME | END  |       | PGDN | PGUP |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |BSPC  |NORMAL|------|       |------| ENTER| SPACE|
  *                                 |      |      |LOWER |       |RAISE |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [INSERT_MODE] = KEYMAP(
    // Left Hand
    X_____X,KC_1,   KC_2,   KC_3,    KC_4,   KC_5, KC_ATM,
    KC_TAB ,KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, KC_LBRC,
    KC_ESC ,KC_A,   KC_S,   KC_D,    KC_F,   KC_G,
    KC_LSFT,KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_LPRN,
    _______,_______,_______,_______, _______,

                                            KC_HOME,KC_END ,
                                            X_____X,
                                            KC_BSPC, TO_NORM, MO(LOWER_MODE),

    // Right Hand
                              KC_ATP , KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS,
                              KC_RBRC, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS,
                                       KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT,
                              KC_RPRN, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_RSFT,
                                             _______,_______, _______,_______,MO(MEDIA),

    KC_PGUP,  KC_PGDN,
    X_____X,
    MO(UPPER_MODE), KC_ENT, KC_SPC
  ),

  //Numeric and Logic/Math layer (Lower)
  [LOWER_MODE] = KEYMAP(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,KC_F1,  KC_F2, KC_F3,  KC_F4,  KC_F5, _______,
    _______,X_____X,   KC_PERCENT,   KC_AMPERSAND, KC_PIPE, KC_ASTERISK,
    _______,KC_1,   KC_2,   KC_3,    KC_4,   KC_5, _______,
    _______,_______,_______,_______, _______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

                              _______,_______,_______,_______,_______,_______,_______,
                              _______,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,_______,
                                      KC_EXCLAIM,KC_PEQL,KC_PLUS,KC_MINS,KC_SLSH,_______,
                              _______,KC_6,KC_7,KC_8,KC_9,KC_0,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),

  //Symbol layer (Upper)
  [UPPER_MODE] = KEYMAP(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,KC_F11,  KC_F12, KC_F13,  KC_F14,  KC_F15, _______,
    _______,KC_AT,   KC_HASH,  KC_GRAVE,  KC_CIRCUMFLEX, X_____X,
    _______,KC_BSLASH,  KC_UNDERSCORE,   KC_PIPE,    KC_TILD,   X_____X, _______,
    _______,_______,_______,_______, _______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

                              _______,_______,_______,_______,_______,_______,_______,
                              _______,KC_F16,KC_F17,KC_F18,KC_F19,KC_F20,_______,
                                      X_____X,KC_DOLLAR,X_____X,X_____X,X_____X,_______,
                              _______,X_____X,X_____X,X_____X,X_____X,X_____X,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),


  [MOUSE] = KEYMAP(
    // Left Hand
    RESET,_______,_______,_______,_______,_______,KC_PGUP,
    _______,_______,_______,_______,_______,_______,KC_PGDN,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,_______,
                              _______,_______,KC_BTN1,KC_BTN3,KC_BTN2,_______,_______,
                                      KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,KC_BTN1,KC_BTN2
  ),
  
  [MEDIA] = KEYMAP(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                      _______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                              _______,_______,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0:
        if (record->event.pressed) { SEND_STRING (VERSION_STRING); }
        break;
  }
return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                 (keyboard_report->mods & MOD_BIT(KC_RSFT));

  switch (keycode) {

    case VIM_A:
      if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
      return false;

    case VIM_B:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
      }
      return false;

    case VIM_C:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_D:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_E:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
      }
      return false;

    case VIM_H:
      switch (VIM_QUEUE) {
        case KC_NO: VIM_LEFT(); break;
        case VIM_C: VIM_CHANGE_LEFT(); break;
        case VIM_D: VIM_DELETE_LEFT(); break;
        case VIM_V: VIM_VISUAL_LEFT(); break;
      }
      return false;

    case VIM_I:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: layer_on(INSERT_MODE); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
        }
      }
      return false;

    case VIM_J:
      switch (VIM_QUEUE) {
        case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
        case VIM_C: VIM_CHANGE_DOWN(); break;
        case VIM_D: VIM_DELETE_DOWN(); break;
        case VIM_V: VIM_VISUAL_DOWN(); break;
      }
      return false;

    case VIM_K:
      switch (VIM_QUEUE) {
        case KC_NO: VIM_UP(); break;
        case VIM_C: VIM_CHANGE_UP(); break;
        case VIM_D: VIM_DELETE_UP(); break;
        case VIM_V: VIM_VISUAL_UP(); break;
      }
      return false;

    case VIM_L:
      switch (VIM_QUEUE) {
        case KC_NO: VIM_RIGHT(); break;
        case VIM_C: VIM_CHANGE_RIGHT(); break;
        case VIM_D: VIM_DELETE_RIGHT(); break;
        case VIM_V: VIM_VISUAL_RIGHT(); break;
      }
      return false;

    case VIM_O:
      if (record->event.pressed) { SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); }
      return false;

    case VIM_P:
      if (record->event.pressed) { SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); }
      return false;

    case VIM_S:
      if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
      return false;

    case VIM_U:
      if (record->event.pressed) { VIM_UNDO(); }
      return false;

    case VIM_V:
      if (record->event.pressed) { VIM_LEADER(VIM_V); }
      return false;

    case VIM_W:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
      }
      return false;

    case VIM_X:
      if (record->event.pressed) { VIM_CUT(); }
      return false;

    case VIM_Y:
      if (record->event.pressed) { SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); }
      return false;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false;
    case VRSN:
      if (record->event.pressed) { SEND_STRING(VERSION_STRING); }
      return false;
    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false;
    case DLEFT:
        if (record->event.pressed) { // Windows move desktop left
          return MACRO(D(LCTL), D(LGUI), T(LEFT), U(LGUI), U(LCTL), END);
        }
        break;
    case DRIGHT:
        if (record->event.pressed) { // Windows move desktop right
          return MACRO(D(LCTL), D(LGUI), T(RIGHT), U(LGUI), U(LCTL), END);
        }
        break;

/*
    case TMUX:
        if (record->event.pressed) { 
          return MACRO(D(LCTL), D(KC_A), U(LCTL), U(KC_A), END);
        }
        break;
*/
  }

  // End by clearing the queue unless keycode is a
  if ((record->event.pressed) &&
       (keycode != VIM_I ||
       keycode != VIM_C ||
       keycode != VIM_D ||
       keycode != VIM_V)) {
     VIM_LEADER(KC_NO);
  }

  return true;
};

void matrix_init_user(void) {
  debug_enable = true;
  VIM_LEADER(KC_NO);
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
