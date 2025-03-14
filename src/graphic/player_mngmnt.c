/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:13 by lslater           #+#    #+#             */
/*   Updated: 2024/11/11 14:49:22 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cube.h"

void	normalize_angle(float *angle)
{
	while (*angle < 0)
		*angle += 2 * M_PI;
	while (*angle >= 2 * M_PI)
		*angle -= 2 * M_PI;
}

void	rotate_player(t_mlx *mlx, t_data *data, int r_angle)
{
	float	angle_step;

	mlx_clear_window(mlx->mlx, mlx->win);
	if (r_angle == 1)
		angle_step = -0.05;
	else
		angle_step = 0.05;
	data->p_angle += angle_step;
	normalize_angle(&data->p_angle);
	raycasting(mlx);
}

void	do_pacman(t_mlx *mlx, float y, float x)
{
	if (mlx->data->ppos_y + y >= mlx->data->rows - 1.125)
		mlx->data->ppos_y = 1.125;
	else if (mlx->data->ppos_x + x >= mlx->data->cols - 1.125)
		mlx->data->ppos_x = 1.125;
	else if (mlx->data->ppos_y + y <= 1)
		mlx->data->ppos_y = mlx->data->rows - 1.125;
	else if (mlx->data->ppos_x + x <= 1)
		mlx->data->ppos_x = mlx->data->cols - 1.125;
	raycasting(mlx);
}

void	move_player(t_mlx *mlx, float speed)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if ((mlx->data->ppos_y + speed > mlx->data->rows)
		|| (mlx->data->ppos_y + speed < 0))
		do_pacman(mlx, speed, speed);
	else if ((mlx->data->ppos_x + speed > mlx->data->cols)
		|| mlx->data->ppos_x + speed < 0)
		do_pacman(mlx, speed, speed);
	else
	{
		mlx->data->ppos_y += speed * sin(mlx->data->p_angle);
		mlx->data->ppos_x += speed * cos(mlx->data->p_angle);
		raycasting(mlx);
	}
}

void	move_sideways(t_mlx *mlx, float speed)
{
	float	side_angle;

	side_angle = mlx->data->p_angle + M_PI_2;
	mlx_clear_window(mlx->mlx, mlx->win);
	if ((mlx->data->ppos_y + speed * sin(side_angle) > mlx->data->rows)
		|| (mlx->data->ppos_y + speed * sin(side_angle) < 0))
		do_pacman(mlx, speed * sin(side_angle), 0);
	else if ((mlx->data->ppos_x + speed * cos(side_angle) > mlx->data->cols)
		|| mlx->data->ppos_x + speed * cos(side_angle) < 0)
		do_pacman(mlx, 0, speed * cos(side_angle));
	else
	{
		mlx->data->ppos_y += speed * sin(side_angle);
		mlx->data->ppos_x += speed * cos(side_angle);
		raycasting(mlx);
	}
}
