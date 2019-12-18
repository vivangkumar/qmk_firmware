/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FNS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FNS   MO(_FN)

#define KC_USC S(KC_MINUS)
#define KC_CLN S(KC_SCLN)
#define KC_PLS S(KC_EQL)
#define KC_TLD S(KC_GRV)
#define KC_DQU S(KC_QUOT)

#define KC_EXC S(KC_1)
#define KC_HSH S(KC_3)
#define KC_DOL S(KC_4)
#define KC_PRC S(KC_5)
#define KC_CRT S(KC_6)
#define KC_AMP S(KC_7)
#define KC_AST S(KC_8)
#define KC_LES S(KC_COMM)
#define KC_GRT S(KC_DOT)

#define KC_GBP A(KC_3)

#define KC_PRV KC_MRWD
#define KC_PLY KC_MPLY
#define KC_NXT KC_MFFD
#define KC_MUT KC__MUTE
#define KC_VLU KC__VOLDOWN
#define KC_VLD KC__VOLUP

#define KC_FWD G(KC_RBRC)
#define KC_BCK G(KC_LBRC)
#define KC_TBL G(S(KC_LBRC))
#define KC_TBR G(S(KC_RBRC))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Fn  | Alt  | GUI  |Lower |Enter | Space| Raise|  Fn  | GUI |  RAlt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,   \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   \
  KC_LCTL, FNS,     KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   FNS,     KC_RGUI, KC_RALT, KC_RCTL    \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   (  |   !  |   <  |   :  |      |      |   =  |   >  |   -  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   *  |   &  |   +  |      |      |   "  |   _  |   %  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   [  |   $  |   £  |   #  |      |      |   |  |   ~  |   ^  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL,  \
  _______, KC_LPRN, KC_EXC,  KC_LES,  KC_CLN,  _______, _______, KC_EQL,  KC_GRT,  KC_MINUS, KC_RPRN, _______, \
  _______, KC_LCBR, KC_AST,  KC_AMP,  KC_PLS,  _______, _______, KC_DQU,  KC_USC,  KC_PRC,  KC_RCBR,  _______, \
  _______, KC_LBRC, KC_DOL,  KC_GBP,  KC_HSH,  _______, _______, KC_PIPE, KC_TLD,  KC_CRT,  KC_RBRC,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Esc | Back | PgUp |  Fwd |      |      |      | TabL |  Up  | TabR |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | PgDn |      |      |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
  KC_ESC,  KC_BCK,  KC_PGUP, KC_FWD,  _______, _______, KC_TBL,  KC_TBL,  KC_UP,  KC_TBR,   _______, _______, \
  _______, _______, KC_PGDN, _______, _______, _______, KC_LEFT, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Fns
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | VolD | Mute | VolU |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Play | Next |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_VLD,  KC_MUT,  KC_VLU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_PRV,  KC_PLY,  KC_NXT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FN);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _FN);
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
      case 0:
          if (active) {
              layer_on(_FN);
          } else {
              layer_off(_FN);
          }
          break;
      case 1:
          if (active) {
              muse_mode = true;
          } else {
              muse_mode = false;
          }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
