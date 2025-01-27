/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:58:18 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/31 15:11:04 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static size_t	ft_len_split(char const *s, char c, char c2)
{
	size_t	i;
	size_t	k;

	k = 1;
	if (s[0] == c || s[0] == c2)
		k = 0;
	i = 1;
	if (!s[0])
		return (0);
	while (s && s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (s[i] != c2 && s[i - 1] == c))
			k += 1;
		i += 1;
	}
	return (k);
}

static size_t	ft_len_next_w(char const *s, char c, char c2, size_t j)
{
	j = 0;
	while (s && s[j] && (s[j] != c && s[j] != c2))
		j += 1;
	return (j);
}

static char	**fill_split(char const *s, char c, char c2, char **result)
{
	size_t	k;
	size_t	i;
	size_t	j;

	i = 0;
	k = 0;
	while (s && s[i])
	{
		j = ft_len_next_w(s + i, c, c2, j);
		if (j != 0)
		{
			result[k] = ft_calloc(sizeof(char), (j + 1));
			if (!result)
			{
				ft_free_split(result);
				return (NULL);
			}
			ft_strlcpy(result[k], s + i, j + 1);
			i += j - 1;
			k += 1;
		}
		i += 1;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_double_split(char const *s, char c, char c2)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc(sizeof(char *), (ft_len_split(s, c, c2) + 2));
	if (!result)
		return (NULL);
	return (fill_split(s, c, c2, result));
}
