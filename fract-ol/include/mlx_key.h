/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:15:31 by sgwon             #+#    #+#             */
/*   Updated: 2026/01/02 15:30:29 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEY_H
# define MLX_KEY_H

typedef enum e_key
{
	KEY_ESC = 65307,
	KEY_F1 = 65470,
	KEY_F2 = 65471,
	KEY_F3 = 65472,
	KEY_F4 = 65473,
	KEY_F5 = 65474,
	KEY_F6 = 65475,
	KEY_F7 = 65476,
	KEY_F8 = 65477,
	KEY_F9 = 65478,
	KEY_F10 = 65479,
	KEY_F11 = 65480,
	KEY_F12 = 65481,
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_SPACE = 32,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_NUMPAD_0 = 65438,
	KEY_NUMPAD_1 = 65436,
	KEY_NUMPAD_2 = 65433,
	KEY_NUMPAD_3 = 65435,
	KEY_NUMPAD_4 = 65430,
	KEY_NUMPAD_5 = 65437,
	KEY_NUMPAD_6 = 65432,
	KEY_NUMPAD_7 = 65429,
	KEY_NUMPAD_8 = 65431,
	KEY_NUMPAD_9 = 65434,
	KEY_NUMPAD_PLUS = 65451,
	KEY_NUMPAD_MINUS = 65453
}	t_key;

typedef enum e_mouse
{
	MOUSE_LEFT_CLICK = 1,
	MOUSE_WHEEL_CLICK = 2,
	MOUSE_RIGHT_CLICK = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5
}	t_mouse;

typedef enum e_event
{
	EVENT_KEY_PRESS = 2,
	EVENT_KEY_RELEASE = 3,
	EVENT_BUTTON_PRESS = 4,
	EVENT_BUTTON_RELEASE = 5,
	EVENT_MOTION_NOTIFY = 6,
	EVENT_DESTROY_NOTIFY = 17
}	t_event;

typedef enum e_mask
{
	MASK_KEY_PRESS = (1L << 0),
	MASK_KEY_RELEASE = (1L << 1),
	MASK_BUTTON_PRESS = (1L << 2),
	MASK_BUTTON_RELEASE = (1L << 3),
	MASK_POINTER_MOTION = (1L << 6),
}	t_mask;

#endif // MLX_KEY_H