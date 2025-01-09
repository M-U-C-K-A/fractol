/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:57:50 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 23:12:19 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

/**
 * @brief Reflects values outside [-1, 1] back into the range.
 * @param z Value to fold.
 * @return Folded value.
 */
static double	box_fold(double z)
{
	if (z > 1)
		z = 2 - z;
	else if (z < -1)
		z = -2 - z;
	return (z);
}

/**
 * @brief Folds a magnitude value to simulate a ball in the Mandelbox.
 * @param r Minimum radius of the ball.
 * @param m Magnitude to fold.
 * @return Folded magnitude.
 */
static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

/**
 * @brief Computes Mandelbox iterations.
 * @param fract Fractal parameters.
 * @param c Complex point to test.
 * @return Iterations before escape or max reached.
 */
int	mandelbox(t_fractal *fract, t_complex *c)
{
	double		mag;
	t_complex	z;
	int			i;

	i = -1;
	mag = 0;
	z.re = c->re;
	z.im = c->im;
	while ((sqrt(mag) < 2) && (++i < fract->iterations))
	{
		z.re = FIXED_RADIUS * box_fold(z.re);
		z.im = FIXED_RADIUS * box_fold(z.im);
		mag = sqrt(z.re * z.re + z.im * z.im);
		z.re = z.re * SCALE * ball_fold(MINIMUM_RADIUS, mag) + c->re;
		z.im = z.im * SCALE * ball_fold(MINIMUM_RADIUS, mag) + c->im;
	}
	return (i);
}
