/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:23:51 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/11/08 15:42:11 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"
#include "includes/utils.h"
#include "utils/libs/libft/libft.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	if (argc == 2)
	{
		data = ft_calloc(sizeof(t_data), 1);
		if (!data)
			return (print_error(MALLOC));
		if (!do_parsing(argv, data))
			init_graphic(data);
		if (data->map)
			ft_magic_free("%2", data->map);
		if (data->flood_fill)
			ft_magic_free("%2", data->flood_fill);
		if (data->colors)
			ft_magic_free("%2", data->colors);
		if (data->textures)
			ft_magic_free("%2", data->textures);
		free(data);
	}
	else
		return (print_error(ARG));
	return (0);
}
