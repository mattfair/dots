#include "config.h"
#include "planck.h"
#include "action_layer.h"
#include "keymap_plover.h"
#include "version.h"

extern keymap_config_t keymap_config;

// Keymap layers
enum planck_layers {
  BASE_QWERTY_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  NAV_LAYER,
  MOUSE_LAYER,
  GUI_LAYER,
  STENO_LAYER,
  KEYBOARD_LAYER
};

// Key aliases for legibility
#define _______ KC_TRNS
#define ___x___ KC_NO

// Window manager keys
#define WM_FULL LALT(LGUI(KC_F))
#define WM_NEXT LCTL(LALT(LGUI(KC_RGHT)))
#define WM_PREV LCTL(LALT(LGUI(KC_LEFT)))
#define WM_NW   LCTL(LGUI(KC_LEFT))
#define WM_N    LALT(LGUI(KC_UP))
#define WM_NE   LCTL(LGUI(KC_RGHT))
#define WM_E    LALT(LGUI(KC_RGHT))
#define WM_SE   S(LCTL(LGUI(KC_RGHT)))
#define WM_S    LALT(LGUI(KC_DOWN))
#define WM_SW   S(LCTL(LGUI(KC_LEFT)))
#define WM_W    LALT(LGUI(KC_LEFT))
#define WM_CNTR LALT(LGUI(KC_C))

#define CTRL_T LCTL(KC_T)
#define CTRL_N LCTL(KC_N)

// Custom key codes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  STENO,
  LOWER,
  RAISE,
  PV_EXIT,
  PV_LOOK,
  SEND_VERSION,
  MOUSE_EXIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   *       ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *       │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *       │ ESC │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │Enter│
   *       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *       │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │
   *       ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *       │  ⌃  │Hyper│  ⌥  │  ⌘  │  ↓  │ NAV │Space│  ↑  │  ⌘  │  ⌥  │ LDR │ GUI │
   *       └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [BASE_QWERTY_LAYER] = {
    {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,   KC_QUOT},
    {KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_ENT},
    {KC_LSPO,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,KC_RSPC},
    {KC_LCTRL, ALL_T(KC_LCTRL), KC_LALT, KC_LGUI, LOWER, MO(NAV_LAYER), KC_SPC, RAISE, KC_RGUI, KC_RALT, KC_LEAD,  MO(GUI_LAYER)}
  },

  /* Numeric and Logic/Math layer (Lower)
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * Application -- │ ⌘-` │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *      window    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    switcher    │     │     │  %  │  &  │  |  │  *  │  !  │  =  │  +  │  -  │  /  │     │ -- Logic symbols and math operators
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │ -- Numbers
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │     │Bksp │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = {
    {LGUI(KC_GRAVE), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______},
    {_______,      ___x___, KC_PERCENT,  KC_AMPERSAND, KC_PIPE, KC_ASTERISK, KC_EXCLAIM, KC_PEQL, KC_PLUS, KC_MINUS,  KC_SLSH, _______},
    {_______,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
    {_______,      _______, _______, _______, _______, ___x___, KC_BSPC, _______, _______, _______, _______, _______}
  },

  /* Symbol layer (Upper)
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │     │ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │  @  │  #  │  `  │  ^  │     │     │  $  │     │     │     │     │ -- Punctuation symbols
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  /
   *                │     │  \  │  _  │  |  │  ~  │     │     │     │     │     │     │     │ /
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │ Del │     │     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = {
    {_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20, _______},
    {_______, KC_AT, KC_HASH, KC_GRAVE, KC_CIRCUMFLEX, ___x___, ___x___, KC_DOLLAR, ___x___, ___x___, ___x___, _______},
    {_______, KC_BSLASH, KC_UNDERSCORE, KC_PIPE, KC_TILD, ___x___, ___x___, ___x___, ___x___, ___x___,  ___x___, _______},
    {_______, _______, _______, _______, _______, KC_DEL,  ___x___,  _______, _______, _______, _______, _______}
  },

  /* Navigation layer
   *
   *         Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │     │     │     │     │     │     │     │Prev │Next │Refsh│     │     │ -- Browser keys
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │  (  │  {  │  [  │     │     │     │     │     │     │  ]  │  }  │  )  │ -- Braces/Brackets
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │     │MOUSE│     │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                                                       '--- Toggle mouse mode
   */
  [NAV_LAYER] = {
    {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_WBAK, KC_WFWD, KC_WREF, ___x___,___x___},
    {_______, ___x___, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___x___, _______},
    {KC_LPRN, KC_LCBR, KC_LBRACKET, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_RBRACKET, KC_RCBR,KC_RPRN},
    {_______, _______, _______, _______, ___x___, ___x___, TG(MOUSE_LAYER), ___x___, _______, _______, _______,_______}
  },

  /* Mouse layer
   *
   *                          Wheel ---/`````````\ Speed /```````````````````\----- Vim-style arrow keys
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │     │     │     │     │     │SPD 0│     │Prev │Next │Refsh│     │     │ -- Browser keys
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │Wh Up│Wh Dw│SPD 1│  ←  │  ↓  │  ↑  │  →  │ Exit│     │ -- Exit mouse mode
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │SPD 2│     │     │     │     │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │ B1  │ B2  │  B3 │     │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                                               \_Mouse Buttons_/
   */
  [MOUSE_LAYER] = {
    {___x___, ___x___, ___x___, ___x___, ___x___, KC_ACL0, ___x___, KC_WBAK, KC_WFWD, KC_WREF, ___x___, ___x___},
    {_______, ___x___, ___x___, KC_WH_U, KC_WH_D, KC_ACL1,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, MOUSE_EXIT,  _______},
    {_______, ___x___, ___x___, ___x___, ___x___, KC_ACL2, ___x___, ___x___, ___x___, ___x___, ___x___, _______},
    {_______, _______, _______, _______, ___x___, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______, _______}
  },


  /* GUI (window management/mouse/media controls) layer
   *
   *                                                            /```````````````````\----- Window manager
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │Wake │     │     │     │     │     │     │Prev │ NW  │  N  │ NE  │ Wake│
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │     │     │Full │  W  │Centr│  E  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │     │     │Next │ SW  │  S  │ SE  │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │Prev │Play │Next │Brig-│Sleep│Sleep│Brig+│Mute │Vol- │Vol+ │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                        \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
   */
  [GUI_LAYER] = {
    {KC_WAKE, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, WM_PREV, WM_NW,   WM_N,    WM_NE,   KC_WAKE},
    {_______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, WM_FULL, WM_W,    WM_CNTR, WM_E,    _______},
    {_______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, WM_NEXT, WM_SW,   WM_S,    WM_SE,   _______},
    {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_SLCK, KC_SLEP, KC_SLEP, KC_PAUS, KC_MUTE, KC_VOLD, KC_VOLU, _______}
  },

  /* Base layer (Qwerty-Steno)
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │  T  │  P  │  H  │           │  F  │  P  │  L  │  T  │  D  │
   *                │     │  S  ├─────┼─────┼─────┤     *     ├─────┼─────┼─────┼─────┼─────┤
   *                │     │     │  K  │  W  │  R  │           │  R  │  B  │  G  │  S  │  Z  │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┬─────┼─────┼─────┼─────┼─────┼─────┤
   *                │Exit │     │     │  A  │  O  │     │     │  E  │  U  │     │     │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [STENO_LAYER] = {
    {PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM, PV_NUM, PV_NUM,  PV_NUM,  PV_NUM, PV_NUM, PV_NUM,  PV_NUM,  PV_NUM},
    {___x___, PV_LS,   PV_LT,   PV_LP,  PV_LH,  PV_STAR, PV_STAR, PV_RF,  PV_RP,  PV_RL,   PV_RT,   PV_RD},
    {___x___, PV_LS,   PV_LK,   PV_LW,  PV_LR,  PV_STAR, PV_STAR, PV_RR,  PV_RB,  PV_RG,   PV_RS,   PV_RZ},
    {PV_EXIT, ___x___, ___x___, PV_A,   PV_O,   KC_SPC,  KC_BSPC, PV_E,   PV_U,   ___x___, ___x___, ___x___}
  },

  /* Keyboard settings layer
   *                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *    Firmware -- │     │Reset│     │     │     │     │     │     │     │     │Vers │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *   Set layer -- │     │Qwert│Steno│     │     │     │     │     │     │     │     │     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *       Audio -- │     │Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│     │     │Aud +│Aud -│     │
   *                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                │     │     │     │     │     │Toggl│Toggl│     │Toggl│ BL- │ BL+ │     │
   *                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                                                    \_____________\_ Backlight _/
   */
  [KEYBOARD_LAYER] = {
    {___x___, RESET,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, SEND_VERSION, ___x___},
    {___x___, QWERTY,    STENO, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,      ___x___},
    {___x___, MUV_DE,   MUV_IN,   MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  ___x___, ___x___, AU_ON,   AU_OFF,       ___x___},
    {___x___, ___x___, ___x___, ___x___, LOWER,   BL_TOGG, BL_TOGG, RAISE,   BL_TOGG, BL_DEC,  BL_INC,       ___x___}
  }
};

#ifdef AUDIO_ENABLE
float startup_sound[][2]    = SONG(STARTUP_SOUND);
float qwerty_sound[][2]     = SONG(QWERTY_SOUND);
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(qwerty_sound);
        #endif
        set_single_persistent_default_layer(BASE_QWERTY_LAYER);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, KEYBOARD_LAYER);
      } else {
        layer_off(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, KEYBOARD_LAYER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, KEYBOARD_LAYER);
      } else {
        layer_off(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, KEYBOARD_LAYER);
      }
      return false;
      case MOUSE_EXIT:
        //exit mouse mode on key up
        if (!record->event.pressed) {
          layer_off(NAV_LAYER);
          layer_off(MOUSE_LAYER);
        }
        break;
    case STENO:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        stop_all_notes();
        PLAY_SONG(plover_song);
#endif
        layer_off(RAISE_LAYER);
        layer_off(LOWER_LAYER);
        layer_off(KEYBOARD_LAYER);
        layer_on(STENO_LAYER);
        if (!eeconfig_is_enabled()) {
          eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
    case PV_EXIT:
      if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(plover_gb_song);
#endif
        layer_off(STENO_LAYER);
      }
      return false;
    case SEND_VERSION:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION " (" QMK_BUILDDATE ")");
      }
      return false;
  }
  return true;
}
