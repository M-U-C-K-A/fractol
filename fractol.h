/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:58:16 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 22:44:29 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "defines.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

//events
int		on_destroy_event(t_engine *engine);
int		on_mouse_hook_event(int key, int x, int y, t_engine *engine);
int		on_key_hook_event(int key, t_engine *engine);
int		on_mousemove_event(int x, int y, t_engine *engine);

//fractals
int		mandelbrot(t_fractal *fract, t_complex *c);
int		julia(t_fractal *fract, t_complex *c, int x, int y);
int		burning_ship(t_fractal *fract, t_complex *c);
int		tricorn(t_fractal *fract, t_complex *c);
int		celtic_mandelbar(t_fractal *fract, t_complex *c);
int		mandelbox(t_fractal *fract, t_complex *c);

//engine
void	change_fractal(int key, t_engine *engine);
void	set_fractal_type(t_engine *engine, char *str);
void	reset_engine(t_engine *engine, int fractal_type);
void	init_engine(t_engine *engine, char *arg);

//render
void	set_pixel_color(t_engine *engine, int x, int y, int color);
void	change_color(int key, t_engine *engine);
void	change_view(int key, t_engine *engine);
int		fractal(t_fractal *fract, t_complex *c, int x, int y);
void	draw_fractal(t_engine *engine);

//utils
void	error_message(char *text, int mode);
void	ft_strlower(char *str);
void	print(char *str, int fd);
void	show_help(void);
