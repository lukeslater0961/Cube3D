/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:38:02 by basverdi          #+#    #+#             */
/*   Updated: 2024/11/09 18:24:52 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_value_for_wall(t_mlx *mlx, int hit, int value)
{
	if (mlx->data->map[mlx->ray->y][mlx->ray->x + value] == '1')
	{
		hit = 1;
		if (mlx->ray->side == 0)
		{
			mlx->ray->wall_hit_pos = mlx->data->ppos_y + \
				mlx->ray->perp_wall_dist * mlx->ray->ray_dir_y;
		}
		else
			mlx->ray->wall_hit_pos = mlx->data->ppos_x + \
				mlx->ray->perp_wall_dist * mlx->ray->ray_dir_x;
		mlx->ray->wall_hit_pos -= floor(mlx->ray->wall_hit_pos);
	}
	return (hit);
}
