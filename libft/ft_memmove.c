/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:40:04 by hdelacou          #+#    #+#             */
/*   Updated: 2024/10/21 20:15:37 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (tmp1 > tmp2)
	{
		while (len--)
			tmp1[len] = tmp2[len];
	}
	else
	{
		while (i < len)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	return (dst);
}
