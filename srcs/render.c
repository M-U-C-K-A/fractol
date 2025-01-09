/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:57 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 22:44:29 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/**
 * @brief Modifies the fractal's color by adding or subtracting
 * red, green, or blue.
 * - Q: adds red
 * - W: adds green
 * - E: adds blue
 * - R: adds yellow
 * - T: adds cyan
 * - Y: adds magenta
 * - A: subtracts red
 * - S: subtracts green
 * - D: subtracts blue
 * - F: subtracts yellow
 * - G: subtracts cyan
 * - H: subtracts magenta
 * @param key The key that was pressed.
 * @param engine The engine containing the fractal to modify.
 */
void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x300000;
	else if (key == KEY_W)
		engine->fractal.color += 0x030000;
	else if (key == KEY_E)
		engine->fractal.color += 0x003000;
	else if (key == KEY_R)
		engine->fractal.color += 0x000300;
	else if (key == KEY_T)
		engine->fractal.color += 0x000030;
	else if (key == KEY_Y)
		engine->fractal.color += 0x000003;
	else if (key == KEY_A)
		engine->fractal.color -= 0x300000;
	else if (key == KEY_S)
		engine->fractal.color -= 0x030000;
	else if (key == KEY_D)
		engine->fractal.color -= 0x003000;
	else if (key == KEY_F)
		engine->fractal.color -= 0x000300;
	else if (key == KEY_G)
		engine->fractal.color -= 0x000030;
	else if (key == KEY_H)
		engine->fractal.color -= 0x000003;
}

/**
 * @brief Handles the view change keys.
 * @details Changes the fractal's offset_x and offset_y
 * depending on the key pressed.
 * @param key The key that was pressed.
 * @param engine The engine containing the fractal information.
 */
void	change_view(int key, t_engine *engine)
{
	t_fractal	*fractal;

	fractal = &engine->fractal;
	if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
}

/**
 * @brief Sets the color of a pixel in the window.
 * @param engine The engine containing the window and image information.
 * @param x The x-coordinate.
 * @param y The y-coordinate of the pixel.
 * @param color The color to be set (32-bit unsigned int, RGBA order).
 */
void	set_pixel_color(t_engine *engine, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	line_len = engine->image.line_len;
	pixel_bits = engine->image.pixel_bits;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(engine->image.addr_ptr + offset) = color;
}

/**
 * @brief Calculates the number of iterations
 * for a given pixel in the fractal image.
 * @param fract The fractal structure.
 * @param c The complex number used for iteration calculations.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return The number of iterations calculated for the given pixel.
 */
int	fractal(t_fractal *fract, t_complex *c, int x, int y)
{
	int	iter;

	iter = 0;
	if (fract->type != JULIA)
		c->im = (y / fract->zoom) + fract->offset_y;
	else if (!fract->is_julia_lock)
		c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == MANDELBROT)
		iter = mandelbrot(fract, c);
	else if (fract->type == JULIA)
		iter = julia(fract, c, x, y);
	else if (fract->type == BURNING_SHIP)
		iter = burning_ship(fract, c);
	else if (fract->type == TRICORN)
		iter = tricorn(fract, c);
	else if (fract->type == MANDELBOX)
		iter = mandelbox(fract, c);
	else if (fract->type == CELTIC_MANDELBAR)
		iter = celtic_mandelbar(fract, c);
	return (iter);
}

/**
 * @brief Renders the fractal.
 * Clears the window, calculates iterations per pixel,
 * sets colors, and displays the image.
 * @param engine The rendering engine.
 */
void	draw_fractal(t_engine *engine)
{
	static t_complex	c;
	t_fractal			*fract;
	int					iter;
	int					x;
	int					y;

	x = -1;
	fract = &engine->fractal;
	mlx_clear_window(engine->mlx, engine->window);
	while (++x < WIDTH)
	{
		y = -1;
		if (fract->type != JULIA)
			c.re = (x / fract->zoom) + fract->offset_x;
		else if (!fract->is_julia_lock)
			c.re = (fract->mouse_x / fract->zoom) + fract->offset_x;
		while (++y < HEIGHT)
		{
			iter = fractal(fract, &c, x, y);
			set_pixel_color(engine, x, y, (iter * engine->fractal.color));
		}
	}
	mlx_put_image_to_window(engine->mlx, engine->window, \
							engine->image.img_ptr, 0, 0);
}
