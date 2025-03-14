/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:13 by lslater           #+#    #+#             */
/*   Updated: 2024/11/11 11:55:00 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "struct.h"

int		init_graphic(t_data *data);
void	gen_minimap(t_mlx *mlx, t_data *data);
int		clear_minimap(t_mlx *mlx);

void	move_player(t_mlx *mlx, float speed);
void	set_textures(t_mlx *mlx);
void	rotate_player(t_mlx *mlx, t_data *data, int r_angle);
int		render(t_mlx *mlx);
float	drawray(t_mlx *mlx, float rangle);
int		raycasting(t_mlx *mlx);
int		check_value_for_wall(t_mlx *mlx, int hit, int value);
void	move_sideways(t_mlx *mlx, float speed);

int		init_window(t_mlx *mlx);
int		windowmap_hook(int event, void *param);
int		window_hook(int event, void *param);

#endif
