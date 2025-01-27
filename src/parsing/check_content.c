/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:43 by bastienverd       #+#    #+#             */
/*   Updated: 2024/11/25 11:47:52 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static int	check_textures(t_data *data)
{
	const char		*texture_prefixes[4] = {"NO", "SO", "WE", "EA"};
	char			**texture;
	static int		i[2] = {-1, 0};

	while (++i[0] < 4 && data->textures[i[0]])
	{
		i[1] = 0;
		while (data->textures[i[0]] && (data->textures[i[0]][i[1]] == '\t'
			|| data->textures[i[0]][i[1]] == ' '))
			i[1]++;
		texture = ft_double_split(&data->textures[i[0]][i[1]], ' ', '	');
		if (!texture[0] || ft_strlen(texture[0]) != 2 || (i[0] < 4 && \
			ft_strcmp(texture[0], texture_prefixes[i[0]])))
			return (free_tab_print_err(MISSING_COORD, texture));
		if (!texture[1])
			return (free_tab_print_err(MISSING_TPATH, texture));
		else if (i[0] < 4 && check_extension(texture[1], ".png"))
			return (free_tab_print_err("", texture));
		if (texture[2])
			return (free_tab_print_err(INV_CHAR_TXT, texture));
		free(data->textures[i[0]]);
		data->textures[i[0]] = ft_strdup(texture[1]);
		ft_free_split(texture);
	}
	return (0);
}

static int	check_colours(t_data *data)
{
	const char	*texture_prefixes[2] = {"F", "C"};
	char		**texture;
	int			i;
	int			j;

	i = 4;
	data->colors = ft_calloc(sizeof(char *), 3);
	if (!data->colors)
		return (print_error(MALLOC));
	while (i <= 5 && data->textures[i])
	{
		j = 0;
		while (data->textures[i] && (data->textures[i][j] == '\t'
			|| data->textures[i][j] == ' '))
			j++;
		texture = ft_split_first_sep(&data->textures[i][j], ' ', '	');
		if (!texture[0] || (ft_strcmp(texture[0], texture_prefixes[i - 4])))
			return (free_tab_print_err(MISSING_COLOR, texture));
		if (!texture[1] || check_rgb(texture))
			return (free_tab_print_err(COLOUR_FORMAT, texture));
		data->colors[i - 4] = ft_strdup(texture[1]);
		ft_magic_free("%2", texture);
		i++;
	}
	return (0);
}

int	parse_texture_line(char **line, t_data *data, int *i)
{
	if (!*line)
	{
		free(*line);
		*line = get_next_line(-42);
		return (1);
	}
	if (ft_strncmp(*line, "\n", 1) == 0)
	{
		free(*line);
		return (0);
	}
	if (ft_strlen(*line) && (*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
	data->textures[*i] = ft_strdup(*line);
	free(*line);
	(*i)++;
	return (0);
}

int	parse_textures(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->textures = ft_calloc(sizeof(char *), 7);
	if (!data->textures)
		return (1);
	line = get_next_line(data->fd);
	if (!line)
		return (1);
	while (line && i <= 5)
	{
		if (parse_texture_line(&line, data, &i))
			return (1);
		line = get_next_line(data->fd);
	}
	data->textures[i] = NULL;
	if (init_map(data, line))
		return (1);
	get_next_line(-42);
	return (0);
}

int	check_file_content(t_data *data)
{
	int	i;

	if (parse_textures(data))
	{
		get_next_line(-42);
		return (1);
	}
	i = 0;
	while (i <= 5)
	{
		if (!data->textures[i])
			return (print_error(MISSING_COORD));
		i++;
	}
	if (check_textures(data) || check_colours(data))
		return (1);
	if (check_texture_files(data))
		return (1);
	return (0);
}
