/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:38:02 by basverdi          #+#    #+#             */
/*   Updated: 2024/11/14 09:08:30 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	keyboard_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 41)
		mlx_loop_end(mlx->mlx);
	if (event == 26)
		move_player(mlx, 0.125);
	if (event == 4)
		move_sideways(mlx, -0.125);
	if (event == 22)
		move_player(mlx, -0.125);
	if (event == 7)
		move_sideways(mlx, 0.125);
	if (event == 80)
		rotate_player(mlx, mlx->data, 1);
	if (event == 79)
		rotate_player(mlx, mlx->data, 0);
	return (0);
}

void	destroy_images(t_mlx *mlx)
{
	if (mlx->texture->north)
		mlx_destroy_image(mlx->mlx, mlx->texture->north);
	if (mlx->texture->south)
		mlx_destroy_image(mlx->mlx, mlx->texture->south);
	if (mlx->texture->east)
		mlx_destroy_image(mlx->mlx, mlx->texture->east);
	if (mlx->texture->west)
		mlx_destroy_image(mlx->mlx, mlx->texture->west);
}

int	init_graphic(t_data *data)
{
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (1);
	mlx->data = data;
	mlx->texture = ft_calloc(sizeof(t_texture), 1);
	if (!mlx->texture)
	{
		free(mlx);
		return (1);
	}
	mlx->mlx = mlx_init();
	set_textures(mlx);
	if (init_window(mlx))
		return (1);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, keyboard_hook, mlx);
	mlx_loop(mlx->mlx);
	destroy_images(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->texture);
	free(mlx);
	return (0);
}
