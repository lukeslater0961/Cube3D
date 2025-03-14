/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:51 by lslater           #+#    #+#             */
/*   Updated: 2024/11/15 09:10:50 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	flood_loop(t_data *data, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map_flood(data, y, x);
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->flood_fill[i][j] == 'S')
				map_flood(data, i, j);
			j++;
		}
		i++;
	}
}

void	flood_extras(t_data *data, int y, int x)
{
	if (y + 2 < data->rows && data->flood_fill[y + 2][x] != ' ' \
		&& data->flood_fill[y + 2][x] && data->flood_fill[y + 2][x] != '1')
		map_flood(data, y + 2, x);
	if (x + 2 < data->cols && data->flood_fill[y][x + 2] != ' ' \
		&& data->flood_fill[y][x + 2] && data->flood_fill[y][x + 2] != '1')
		map_flood(data, y, x + 2);
	if (y - 2 >= 0 && data->flood_fill[y - 2][x] != ' ' \
		&& data->flood_fill[y - 2][x] && data->flood_fill[y - 2][x] != '1')
		map_flood(data, y - 2, x);
	if (x - 2 >= 0 && data->flood_fill[y][x - 2] != ' ' \
		&& data->flood_fill[y][x - 2] && data->flood_fill[y][x - 2] != '1')
		map_flood(data, y, x - 2);
}

void	map_flood(t_data *data, int y, int x)
{
	if (data->flood_fill[y][x] == '7' || data->flood_fill[y][x] == '1')
		return ;
	data->flood_fill[y][x] = '7';
	if (y + 1 < data->rows && data->flood_fill[y + 1][x] != ' ' \
		&& data->flood_fill[y + 1][x] && data->flood_fill[y + 1][x] != '1')
		map_flood(data, y + 1, x);
	if (x + 1 < data->cols && data->flood_fill[y][x + 1] != ' ' \
		&& data->flood_fill[y][x + 1] && data->flood_fill[y][x + 1] != '1')
		map_flood(data, y, x + 1);
	if (y - 1 >= 0 && data->flood_fill[y - 1][x] != ' ' \
		&& data->flood_fill[y - 1][x] && data->flood_fill[y - 1][x] != '1')
		map_flood(data, y - 1, x);
	if (x - 1 >= 0 && data->flood_fill[y][x - 1] != ' ' \
		&& data->flood_fill[y][x - 1] && data->flood_fill[y][x - 1] != '1')
		map_flood(data, y, x - 1);
	flood_extras(data, y, x);
}
