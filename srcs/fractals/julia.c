/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:02:12 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 23:16:38 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

/**
 * @brief Computes iterations for the Julia fractal.
 * Computes iterations for the Julia fractal.
 * @param fract Fractal parameters.
 * @param c Constant complex number used in the iteration formula.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return Iterations before escape or max reached.
 */
int	julia(t_fractal *fract, t_complex *c, int x, int y)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = (x / fract->zoom) + fract->offset_x;
	z.im = (y / fract->zoom) + fract->offset_y;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}
