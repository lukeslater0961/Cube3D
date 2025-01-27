/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:48:17 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/11/19 13:33:56 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_rgb(char **texture)
{
	char	**rgb;
	char	*tmp;
	int		i;

	tmp = remove_spaces_tabs(texture[1]);
	rgb = ft_split(tmp, ',');
	free(tmp);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (free_tab_print_err("", rgb));
	i = 0;
	while (i < 3)
	{
		tmp = remove_spaces_tabs(rgb[i]);
		if (!tmp || check_value_range(tmp, rgb))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	ft_magic_free("%2", rgb);
	return (0);
}

int	check_extension(char *filename, char *extension_name)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension)
		extension[ft_strlen(extension)] = '\0';
	if (!extension || ft_strcmp(extension, extension_name))
		return (print_error(FILE_INVE));
	return (0);
}

int	check_rights(char *filename, t_data *data, int type)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (errno == EISDIR)
		return (print_error(FILE_ISDIR));
	else if (fd == -1)
		return (print_error(FILE_DE));
	else if (type == -42)
		data->fd = fd;
	return (0);
}

int	check_file(char *filename, t_data *data)
{
	if (check_extension(filename, ".cub"))
		return (1);
	if (check_rights(filename, data, -42))
		return (1);
	return (0);
}

int	check_texture_files(t_data *data)
{
	int	i;

	i = 0;
	while (data->textures[i] && i < 4)
	{
		if (check_rights(data->textures[i], data, -42))
			return (1);
		close(data->fd);
		i++;
	}
	return (0);
}
