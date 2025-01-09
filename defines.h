/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:59:36 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/09 20:25:45 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MANDELBROT 1
#define JULIA 2
#define BURNING_SHIP 3
#define TRICORN 4
#define MANDELBOX 5
#define CELTIC_MANDELBAR 6

#define MANDELBROT_STR "mandelbrot"
#define JULIA_STR "julia"
#define BURNING_SHIP_STR "burning_ship"
#define TRICORN_STR "tricorn"
#define MANDELBOX_STR "mandelbox"
#define CELTIC_MANDELBAR_STR "celtic_mandelbar"

#define WIN_SIZE			500
#define WIDTH				1080
#define HEIGHT				540
#define VIEW_CHANGE_SIZE	60
#define MIN_ITERATIONS		256
#define MAX_ITERATIONS		256
#define DEFAULT_COLOR		265

#define SCALE 2
#define FIXED_RADIUS 1
#define MINIMUM_RADIUS 0.5

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	int			type;
	double		zoom;
	u_int32_t	color;
	double		mouse_x;
	double		mouse_y;
	double		offset_x;
	double		offset_y;
	int			iterations;
	bool		is_julia_lock;
}	t_fractal;

typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}	t_engine;

enum e_keys
{
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_R = 114,
	KEY_T = 116,
	KEY_Y = 121,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_L = 108,
	MOUSE_LEFT_CLK = 1,
	MOUSE_SCRL_CLK = 2,
	MOUSE_RIGHT_CLK = 3,
	MOUSE_SCRL_DOWN = 4,
	MOUSE_SCRL_UP = 5,
};
