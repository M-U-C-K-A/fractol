/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:06:13 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 23:12:45 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

/**
 * @brief Computes iterations for the Celtic Mandelbar fractal.
 * @param fract Fractal parameters.
 * @param c Complex point to test.
 * @return Iterations before escape or max reached.
 */
int	celtic_mandelbar(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im;
		z.im = -2 * z.re * z.im + c->im;
		if (re_temp < 0)
			re_temp *= -1;
		z.re = re_temp + c->re;
	}
	return (i);
}
