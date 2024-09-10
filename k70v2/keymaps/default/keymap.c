// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

enum anne_pro_keycodes {
  SOCD_W = SAFE_RANGE,
  SOCD_A,
  SOCD_S,
  SOCD_D,
  ENC_A,
  ENC_B
};


bool w_down = false;
bool a_down = false;
bool s_down = false;
bool d_down = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Scr│Pse│
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │               │ 4 │ 5 │ 6 │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
     */

	
	[0] = LAYOUT_fullsize_ansi(
	KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PRINT_SCREEN, KC_SCROLL_LOCK,
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BACKSPACE,
    KC_TAB, KC_Q, SOCD_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_INSERT,
    KC_CAPS_LOCK, SOCD_A, SOCD_S, SOCD_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, KC_ENTER, KC_DELETE,
    KC_LEFT_SHIFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_RIGHT_SHIFT, KC_UP,
    KC_LEFT_CTRL, KC_LEFT_GUI, KC_LEFT_ALT, KC_CALCULATOR, KC_AUDIO_VOL_DOWN, KC_SPACE, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_NO, KC_RIGHT_ALT, KC_RIGHT_GUI, KC_APPLICATION, KC_RIGHT_CTRL, KC_LEFT, KC_DOWN,
    KC_NO ,KC_PAUSE, KC_HOME, KC_PAGE_UP, KC_NUM_LOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_END, KC_PAGE_DOWN, KC_KP_7 ,KC_KP_8, KC_NO,KC_NO, KC_RIGHT,
    KC_NO ,KC_KP_9, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_NO, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT ,KC_KP_ENTER, KC_NO,KC_NO, KC_KP_0,
	KC_NO ,KC_NO, KC_NO, KC_MEDIA_STOP, KC_MEDIA_PREV_TRACK, KC_NO, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO, KC_NO, KC_NO ,KC_NO, KC_NO,ENC_A, ENC_B
	)
};


int ENCODER_A = 0;
int ENCODER_B = 0;


#define enc_res 2
int VOL_CLICKS = enc_res;

//tap_code(KC_AUDIO_VOL_DOWN); // Volume up or replace with your desired action
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
    switch (keycode) {		 
		 case ENC_A:
			ENCODER_A = (record->event.pressed); 
			if (record->event.pressed) { // Low to high
				if (ENCODER_B) {

					if(VOL_CLICKS > 0){
						VOL_CLICKS=VOL_CLICKS-1;
					}else{
						tap_code(KC_AUDIO_VOL_DOWN);
						VOL_CLICKS = enc_res;
					}
					
				} else {
										
					if(VOL_CLICKS < (enc_res*2)){
						VOL_CLICKS=VOL_CLICKS+1;
					}else{
						tap_code(KC_AUDIO_VOL_UP);
						VOL_CLICKS = enc_res;
					}
						
				}
			}
            return false;
            break;

        case ENC_B:
			ENCODER_B = (record->event.pressed); 
            if (record->event.pressed) {
				if (ENCODER_A) {
										
					if(VOL_CLICKS < (enc_res*2)){
						VOL_CLICKS=VOL_CLICKS+1;
					}else{
						tap_code(KC_AUDIO_VOL_UP);
						VOL_CLICKS = enc_res;
					}
						
				} else {
					
					if(VOL_CLICKS > 0){
						VOL_CLICKS=VOL_CLICKS-1;
					}else{
						tap_code(KC_AUDIO_VOL_DOWN);
						VOL_CLICKS = enc_res;
					}
						
				}                           
            }
            return false;
            break;
   
		case SOCD_W:
			if (record->event.pressed) {
				if (s_down) {
					unregister_code(KC_S);
				}
				register_code(KC_W);
				w_down = true;
			} else {
				unregister_code(KC_W);
				w_down = false;

				if (s_down) {
					register_code(KC_S);
				}

			}
			return false;
			break;
		case SOCD_A:
			if (record->event.pressed) {
				if (d_down) {
					unregister_code(KC_D);
				}
				register_code(KC_A);
				a_down = true;
			} else {
				unregister_code(KC_A);
				a_down = false;

				if (d_down) {
					register_code(KC_D);
				}

			}
			return false;
			break;
		case SOCD_S:
			if (record->event.pressed) {
				if (w_down) {
					unregister_code(KC_W);
				}
				register_code(KC_S);
				s_down = true;
			} else {
				unregister_code(KC_S);
				s_down = false;

				if (w_down) {
					register_code(KC_W);
				}

			}
			return false;
			break;
		case SOCD_D:
			if (record->event.pressed) {
				if (a_down) {
					unregister_code(KC_A);
				}
				register_code(KC_D);
				d_down = true;
			} else {
				unregister_code(KC_D);
				d_down = false;

				if (a_down) {
					register_code(KC_A);
				}
			}
			return false;
			break;
    }
	
	
	 
    return true;
}