/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/11/08 15:42:51 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "library.h"

typedef struct s_ray
{
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	float	ray_dir_x;
	float	ray_dir_y;
	int		step_x;
	int		step_y;
	int		x;
	int		y;
	int		side;
	float	wall_hit_pos;
	float	perp_wall_dist;
	int		orientation;
	int		lineh;
}				t_ray;

typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int		size;
}		t_texture;

typedef struct s_data
{
	int			fd;
	char		**colors;
	char		**map;
	int			rows;
	int			cols;
	char		**flood_fill;
	char		**textures;
	char		player_orientation;
	float		ppos_y;
	float		ppos_x;
	float		p_angle;
}			t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*winmap;
	t_data		*data;
	t_ray		*ray;
	t_texture	*texture;
}				t_mlx;

union u_color
{
	int	value;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
};

#endif 
