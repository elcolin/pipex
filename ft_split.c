/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:02:55 by ecolin            #+#    #+#             */
/*   Updated: 2022/03/24 16:40:14 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdio.h>

size_t	l_size(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			while (s[i] == c && s[i])
				i++;
	}
	return (j);
}

int	alloc_error(size_t j, char **tab)
{
	if (tab[j])
		return (0);
	while ((int long long)j >= 0)
	{
		j--;
		if (tab[j])
			free(tab[j]);
	}
	free(tab);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	dst = malloc(((k = l_size(s, c)) + 1) * sizeof(char *));
	if (!dst)
		return (0);
	dst[k] = 0;
	while (*s)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (i > 0 && j < k)
		{
			dst[j] = malloc(i + 1);
			if (alloc_error(j, dst))
				return (0);
			ft_strlcpy(dst[j++], ((char *) s), i + 1);
		}
		s += i + 1;
	}
	return (dst);
}
