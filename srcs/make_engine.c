/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:44 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/17 21:22:42 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/**
 * @brief Handles the fractal type change keys.
 * @details Resets the fractal structure and assigns
 * the new fractal type based on the key pressed.
 * @param key The key that was pressed.
 * @param engine The engine containing the fractal information.
 */
void	change_fractal(int key, t_engine *engine)
{
	reset_engine(engine, MANDELBROT);
	if (key == KEY_TWO)
		engine->fractal.type = JULIA;
	else if (key == KEY_THREE)
		engine->fractal.type = BURNING_SHIP;
	else if (key == KEY_FOUR)
		engine->fractal.type = TRICORN;
	else if (key == KEY_FIVE)
		engine->fractal.type = MANDELBOX;
	else if (key == KEY_SIX)
		engine->fractal.type = CELTIC_MANDELBAR;
}

/**
 * @brief Set the fractal type based on a given string.
 * - mandelbrot
 * - julia
 * - burning ship
 * - tricorn
 * - mandelbox
 * - celtic mandelbar
 * @param engine The engine containing the fractal to modify.
 * @param str The string to match against valid fractal types.
 */
void	set_fractal_type(t_engine *engine, char *str)
{
	size_t	len;

	if (!engine || !str)
		return ;
	ft_strlower(str);
	len = ft_strlen(str);
	if (ft_strncmp(str, MANDELBROT_STR, len) == 0)
		engine->fractal.type = MANDELBROT;
	else if (ft_strncmp(str, JULIA_STR, len) == 0)
		engine->fractal.type = JULIA;
	else if (ft_strncmp(str, BURNING_SHIP_STR, len) == 0)
		engine->fractal.type = BURNING_SHIP;
	else if (ft_strncmp(str, TRICORN_STR, len) == 0)
		engine->fractal.type = TRICORN;
	else if (ft_strncmp(str, MANDELBOX_STR, len) == 0)
		engine->fractal.type = MANDELBOX;
	else if (ft_strncmp(str, CELTIC_MANDELBAR_STR, len) == 0)
		engine->fractal.type = CELTIC_MANDELBAR;
	else
		show_help();
}

/**
 * @brief Resets the engine for a given fractal type.
 * @param engine The engine to reset.
 * @param fractal_type The fractal type.
 */
void	reset_engine(t_engine *engine, int fractal_type)
{
	engine->fractal.type = fractal_type;
	engine->fractal.zoom = 100 * WIDTH / HEIGHT;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.is_julia_lock = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MIN_ITERATIONS;
}

/**
 * @brief Initializes the rendering engine with specified parameters.
 * @param engine A pointer to the engine structure to initialize.
 * @param arg A string argument specifying the initial fractal type.
 */
void	init_engine(t_engine *engine, char *arg)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine || !arg)
		return ;
	reset_engine(engine, MANDELBROT);
	set_fractal_type(engine, arg);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIDTH, HEIGHT, \
												"Fractol project");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIDTH, HEIGHT);
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		mlx_destroy_window(engine->mlx, engine->window);
		error_message("[MLX ERROR]: can't handle object creation!\n", 1);
	}
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}
