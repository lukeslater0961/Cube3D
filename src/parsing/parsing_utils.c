/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:47:37 by basverdi          #+#    #+#             */
/*   Updated: 2024/11/14 16:26:57 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i += 1;
	if (!s1 || !s2)
		return (0);
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

void	process_short_lines(t_data *data)
{
	char	**tmp_line;
	int		i;
	int		j;

	i = 0;
	tmp_line = NULL;
	tmp_line = ft_duptab(data->map, tmp_line, data->rows, data->cols);
	ft_magic_free("%2", data->map);
	data->map = ft_calloc(sizeof(char *), data->rows + 1);
	while (tmp_line[i])
	{
		data->map[i] = ft_calloc(sizeof(char *), data->cols + 1);
		if ((ft_strlen(tmp_line[i]) <= (size_t)data->cols))
		{
			ft_strlcpy(data->map[i], tmp_line[i], ft_strlen(tmp_line[i]) + 1);
			j = ft_strlen(tmp_line[i]) + 1;
			while (j++ <= data->cols)
				data->map[i][j] = ' ';
		}
		else
			ft_strlcpy(data->map[i], tmp_line[i], ft_strlen(tmp_line[i]));
		i++;
	}
	ft_magic_free("%2", tmp_line);
}

int	check_value_range(char *str, char **rgb)
{
	int	val;

	if (!ft_isallnum(str))
		return (free_tab_print_err("", rgb));
	if (ft_overflow(str))
		return (free_tab_print_err("", rgb));
	val = ft_atoi(str);
	if (val < 0 || val > 255)
		return (free_tab_print_err("", rgb));
	return (0);
}

int	is_newline(char *line)
{
	if (!ft_strncmp("\n", line, 1))
	{
		if (line)
			free(line);
		return (1);
	}
	return (0);
}

void	skip_newline(char **line, t_data *data)
{
	while (!ft_strncmp(*line, "\n", 1))
	{
		free(*line);
		*line = get_next_line(data->fd);
		if (*line == NULL)
			return ;
	}
}
