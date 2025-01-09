/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:21 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 22:43:59 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/**
 * @brief Destroys image and window, then exits.
 * @param engine The engine containing the resources to destroy.
 */
int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}

/**
 * @brief Handles mouse scroll events for zooming.
 * @param key The mouse button code indicating scroll direction.
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param engine The engine containing the fractal to modify.
 * @return Always returns 0.
 */
int	on_mouse_hook_event(int key, int x, int y, t_engine *engine)
{
	t_fractal	*fr;

	fr = &engine->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
		if (fr->iterations < MAX_ITERATIONS)
			++fr->iterations;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
		if (fr->iterations > MIN_ITERATIONS)
			--fr->iterations;
	}
	draw_fractal(engine);
	return (0);
}

/**
 * @brief Handles key press events for modifying the fractal.
 * @details Changes the fractal's color, view, or type based on the key pressed.
 * - Q-Y and A-H: change the fractal's color
 * - Arrows: move the fractal's view
 * - 1-5: switch to a different fractal
 * - L: toggle Julia set's locking of the mouse position
 * - 0: reset the fractal to its default state
 * - ESC: exit the program
 * @param key The key that was pressed.
 * @param engine The engine containing the fractal to modify.
 * @return Always returns 0.
 */
int	on_key_hook_event(int key, t_engine *engine)
{
	if ((key >= KEY_Q && key <= KEY_Y) || (key >= KEY_A && key <= KEY_H))
		change_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		change_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FIVE)
		change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA)
		engine->fractal.is_julia_lock ^= 1;
	else if (key == KEY_ZERO)
		reset_engine(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		on_destroy_event(engine);
	draw_fractal(engine);
	return (0);
}

/**
 * @brief Handles mouse move events to modify the Julia set.
 * @details Changes the Julia set's position based on the mouse position,
 * but only if the Julia set is unlocked or not set to the Julia set.
 * @param x The x coordinate of the mouse.
 * @param y The y coordinate of the mouse.
 * @param engine The engine containing the Julia set to modify.
 * @return Always returns 0.
 */
int	on_mousemove_event(int x, int y, t_engine *engine)
{
	if (!(engine->fractal.type == JULIA) || engine->fractal.is_julia_lock)
		return (0);
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	draw_fractal(engine);
	return (0);
}
