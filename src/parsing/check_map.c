/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:33:43 by basverdi          #+#    #+#             */
/*   Updated: 2024/11/15 09:14:32 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	is_border(int i, int j, int rows, int cols)
{
	return (i == 0 || j == 0 || i == rows - 1 || j == cols - 1);
}

int	check_map_position(t_data *data, int i, int j)
{
	if (data->flood_fill[i][j] == '7')
	{
		if (is_border(i, j, data->rows, data->cols)
			|| ((i + 1 > data->rows - 1 || data->flood_fill[i + 1][j] == ' '
				|| !data->flood_fill[i + 1][j]) || (i - 1 < 0
				|| data->flood_fill[i - 1][j] == ' '
				|| !data->flood_fill[i - 1][j]) || (j + 1 > data->cols - 1
				|| data->flood_fill[i][j + 1] == ' '
				|| !data->flood_fill[i][j + 1]) || (j - 1 < 0
				|| data->flood_fill[i][j - 1] == ' '
				|| !data->flood_fill[i][j - 1])))
			return (print_error(MAP_OPEN));
	}
	return (0);
}
