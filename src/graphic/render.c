/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:36:44 by basverdi          #+#    #+#             */
/*   Updated: 2024/11/25 11:34:12 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cube.h"

int	getcolor(char *colorStr)
{
	union u_color	color;
	char			**str_tmp;

	str_tmp = ft_split(colorStr, ',');
	color.a = 255;
	color.r = ft_atoi(str_tmp[0]);
	color.g = ft_atoi(str_tmp[1]);
	color.b = ft_atoi(str_tmp[2]);
	ft_magic_free("%2", str_tmp);
	return (color.value);
}

void	set_wall_texture(t_mlx *mlx, int currenth, int y, int column)
{
	float	texture_x;
	float	texture_y;
	int		color;

	color = 0;
	texture_x = mlx->ray->wall_hit_pos * 1024;
	texture_y = (float)((float)currenth / (float)mlx->ray->lineh) *1024;
	if (mlx->ray->orientation == 1)
		color = mlx_get_image_pixel(mlx->mlx, mlx->texture->west, texture_x, \
								texture_y);
	else if (mlx->ray->orientation == 2)
		color = mlx_get_image_pixel(mlx->mlx, mlx->texture->east, texture_x, \
								texture_y);
	else if (mlx->ray->orientation == 3)
		color = mlx_get_image_pixel(mlx->mlx, mlx->texture->north, texture_x, \
								texture_y);
	else if (mlx->ray->orientation == 4)
		color = mlx_get_image_pixel(mlx->mlx, mlx->texture->south, texture_x, \
								texture_y);
	mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, color);
}

int	render_wall(t_mlx *mlx, int column, float length_dir, float ray_angle)
{
	int	currenth;
	int	y;

	y = 0;
	currenth = 0;
	length_dir *= cos(mlx->data->p_angle - ray_angle);
	if (length_dir == 0)
		mlx->ray->lineh = WINHEIGHT;
	else
		mlx->ray->lineh = WINHEIGHT / length_dir;
	y = (WINHEIGHT / 2) - (mlx->ray->lineh / 2);
	if (y < 0)
		currenth = -y;
	while (currenth < mlx->ray->lineh)
	{
		if (y + currenth >= WINHEIGHT || y + currenth < 0)
			break ;
		set_wall_texture(mlx, currenth, y, column);
		currenth++;
	}
	return (0);
}

int	raycasting(t_mlx *mlx)
{
	t_ray	*ray;
	float	length_dir;
	float	rangle;
	int		column;

	column = 0;
	ray = ft_calloc(sizeof(t_ray), 1);
	if (!ray)
		return (print_error(MALLOC));
	mlx->ray = ray;
	rangle = mlx->data->p_angle - M_PI / 6;
	render(mlx);
	while (rangle < mlx->data->p_angle + M_PI / 6)
	{
		length_dir = drawray(mlx, rangle);
		render_wall(mlx, column, length_dir, rangle);
		rangle += (M_PI / 3) / WINWIDTH;
		column++;
	}
	free(ray);
	return (0);
}

int	render(t_mlx *mlx)
{
	int	x;
	int	y;
	int	ceiling;
	int	floor;

	y = 0;
	floor = getcolor(mlx->data->colors[0]);
	ceiling = getcolor(mlx->data->colors[1]);
	while (y < WINHEIGHT)
	{
		x = 0;
		while (x < WINWIDTH)
		{
			if (y <= WINHEIGHT / 2)
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, ceiling);
			else
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, floor);
			x++;
		}
		y++;
	}
	return (0);
}
