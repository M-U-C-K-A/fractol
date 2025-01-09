/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:58:06 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/08 23:34:33 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/**
 * Prints error message and exits.
 * @param text The error message. If NULL, does nothing.
 * @param mode If 0, uses perror(); otherwise, ft_putstr_fd().
 */
void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief Convert a given string to lowercase.
 * @param str The string to convert.
 */
void	ft_strlower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		str[i] = ft_tolower((int)str[i]);
}

/**
 * @brief Prints a given string to a given file descriptor.
 * @param str The string to print.
 * @param fd The file descriptor to write to.
 */
void	print(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}

/**
 * @brief Displays a help message and exits successfully.
 */
void	show_help(void)
{
	print("\n", 1);
	print(" ╔════════════════════ Let me help you! ════════════════════╗\n", 1);
	print(" ║                                                          ║\n", 1);
	print(" ║ Usage: ./fractol  mandelbrot                             ║\n", 1);
	print(" ║                   julia                                  ║\n", 1);
	print(" ║                   burning_ship                           ║\n", 1);
	print(" ║                   tricorn                                ║\n", 1);
	print(" ║                   mandelbox                              ║\n", 1);
	print(" ║                   celtic_mandelbar                       ║\n", 1);
	print(" ║                                                          ║\n", 1);
	print(" ║ examples: ./fractol mandelbrot                           ║\n", 1);
	print(" ║                                                          ║\n", 1);
	print(" ╠════════════════════════ KEYBOARD ════════════════════════╣\n", 1);
	print(" ║                                                          ║\n", 1);
	print(" ║ ◇ Press ESC to close the window                          ║\n", 1);
	print(" ║ ◇ Press one of [1═6] to move to another fractal          ║\n", 1);
	print(" ║ ◇ Press one of [Q═Y] keys to change the color of fractal ║\n", 1);
	print(" ║ ◇ Press one of [A═H] keys to change the color of fractal ║\n", 1);
	print(" ║ ◇ Use mouse scroll to zoom in and out of the fractal     ║\n", 1);
	print(" ║ ◇ Press the arrow keys to change the viewpoint           ║\n", 1);
	print(" ║ ◇ Press L to lock Julia's fractal                        ║\n", 1);
	print(" ║ ◇ Press Zero to reset the fractal                        ║\n", 1);
	print(" ╚══════════════════════════════════════════════════════════╝\n", 1);
	print("\n", 1);
	exit(EXIT_SUCCESS);
}
