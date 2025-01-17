/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:28:11 by hdelacou          #+#    #+#             */
/*   Updated: 2024/10/26 20:09:52 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	nb;
	int	prev;

	nb = 0;
	prev = 0;
	while (*s != '\0')
	{
		if (prev == 2 && *s == c && prev != 0)
		{
			prev = 1;
			nb++;
		}
		if (*s != c)
			prev = 2;
		s++;
		if (prev == 2 && *s == '\0')
			nb++;
	}
	return (nb);
}

static void	ft_free(char **tabstr)
{
	int	i;

	i = 0;
	while (tabstr[i])
	{
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
}

static char	**ft_splitwords(char **tabstr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	old_i;

	i = -1;
	k = 0;
	while (s[++i] != '\0' && i < ft_strlen(s) + 1)
	{
		old_i = i;
		j = 0;
		while (s[i] != c && s[i] != '\0' && ++j)
			i++;
		if ((s[i] == c || s[i] == '\0') && j != 0)
		{
			tabstr[k++] = ft_substr(s, old_i, j);
			if (tabstr[k - 1] == NULL)
			{
				ft_free(tabstr);
				return (NULL);
			}
		}
	}
	tabstr[k] = NULL;
	return (tabstr);
}

char	**ft_split(char const *s, char c)
{
	int		nbword;
	char	**tabstr;

	nbword = ft_countwords(s, c);
	tabstr = malloc((nbword + 1) * sizeof(char *));
	if (tabstr == NULL)
		return (NULL);
	return (ft_splitwords(tabstr, s, c));
}
