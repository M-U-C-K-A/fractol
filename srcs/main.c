/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:39 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 22:35:20 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/**
 * @brief Main function to launch the program.
 * @param[in] argc The number of arguments passed to the program.
 * @param[in] argv The arguments passed to the program.
 * @return 0 if the program runs successfully.
 */
int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
		show_help();
	init_engine(&engine, argv[1]);
	draw_fractal(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook_event, &engine);
	mlx_hook(engine.window, 6, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
