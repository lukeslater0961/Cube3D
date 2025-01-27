/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:22:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/11/15 13:53:31 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	set_textures(t_mlx *mlx)
{
	mlx->texture->size = 1024;
	mlx->texture->north = mlx_png_file_to_image(mlx->mlx, \
			mlx->data->textures[0], \
			&mlx->texture->size, &mlx->texture->size);
	mlx->texture->south = mlx_png_file_to_image(mlx->mlx, \
			mlx->data->textures[1], \
			&mlx->texture->size, &mlx->texture->size);
	mlx->texture->west = mlx_png_file_to_image(mlx->mlx, \
			mlx->data->textures[2], \
			&mlx->texture->size, &mlx->texture->size);
	mlx->texture->east = mlx_png_file_to_image(mlx->mlx, \
			mlx->data->textures[3], \
			&mlx->texture->size, &mlx->texture->size);
}

char	**ft_duptab(char **src, char **dest, int len, int cols)
{
	int		i;
	size_t	j;
	size_t	ncols;

	ncols = cols;
	i = 0;
	j = 0;
	dest = ft_calloc(sizeof(char *), len + 2);
	if (!dest)
		return (NULL);
	while (i <= len - 1)
	{
		dest[i] = ft_calloc(sizeof(char *), cols + 2);
		ft_strlcpy(dest[i], src[i], cols + 1);
		j = ft_strlen(src[i]);
		while (j < ncols)
		{
			dest[i][j] = '\0';
			j++;
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int	process_line(char **line)
{
	if (ft_strlen(*line) && (*line)[ft_strlen(*line) - 1] == '\n')
	{
		if (ft_strlen(*line) > 1)
			(*line)[ft_strlen(*line) - 1] = '\0';
	}
	return (ft_strlen(*line) > 0);
}

int	check_for_player(char c, t_data *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->ppos_y != 0.0)
			return (print_error(PLAYER_NUM));
		data->player_orientation = data->map[i][j];
		data->ppos_y = i + 0.625;
		data->ppos_x = j + 0.625;
		flood_loop(data, i, j);
	}
	return (0);
}

char	*remove_spaces_tabs(char *str)
{
	int		i;
	int		j;
	char	*cleaned;

	cleaned = ft_calloc(sizeof(char *), ft_strlen(str) + 1);
	if (!cleaned)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			cleaned[j++] = str[i];
		i++;
	}
	cleaned[j] = '\0';
	return (cleaned);
}
