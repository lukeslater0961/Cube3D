/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:58:13 by lslater           #+#    #+#             */
/*   Updated: 2024/11/15 09:05:04 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	add_line_to_map(t_data *data, char *line, int *i, int *capacity)
{
	int		j;
	char	**new_map;

	j = 0;
	if (*i + 1 >= *capacity)
	{
		*capacity *= 2;
		new_map = ft_calloc(*capacity, sizeof(char *));
		if (!new_map)
			return (1);
		while (j < *i)
		{
			new_map[j] = data->map[j];
			j++;
		}
		free(data->map);
		data->map = new_map;
	}
	data->map[*i] = ft_strdup(line);
	if (!data->map[*i])
		return (1);
	(*i)++;
	data->map[*i] = NULL;
	return (0);
}

int	handle_line(t_data *data, char *line, int *i, int *capacity)
{
	if (process_line(&line) && add_line_to_map(data, line, i, capacity))
		return (1);
	return (0);
}

int	init_map(t_data *data, char *line)
{
	int		i;
	int		capacity;

	i = 0;
	capacity = 1;
	data->map = ft_calloc(capacity, sizeof(char *));
	if (!data->map)
		return (1);
	skip_newline(&line, data);
	while (line)
	{
		if (is_newline(line))
			return(print_error(MAP_NL));
		if (handle_line(data, line, &i, &capacity))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	return (0);
}

int	is_map_closed(t_data *data, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (check_map_position(data, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_chars_map(t_data *data, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols && data->flood_fill[i][j])
		{
			if (data->flood_fill[i][j] != '1' && data->flood_fill[i][j] != '0'
					&& data->flood_fill[i][j] != 32
					&& data->flood_fill[i][j] != 'N'
					&& data->flood_fill[i][j] != 'S'
					&& data->flood_fill[i][j] != 'E'
					&& data->flood_fill[i][j] != 'W')
				return (print_error(INV_CHAR));
			j++;
		}
		i++;
	}
	return (0);
}
