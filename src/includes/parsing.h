/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:39:26 by bananabread       #+#    #+#             */
/*   Updated: 2024/11/14 16:03:52 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

int		check_file(char *filename, t_data *data);
int		check_rights(char *filename, t_data *data, int type);

int		check_file_content(t_data *data);
int		check_extension(char *filename, char *extension_name);
int		check_rgb(char **texture);
int		check_texture_files(t_data *data);

int		do_parsing(char **argv, t_data *data);
char	**ft_duptab(char **src, char **dest, int len, int cols);

int		add_line_to_map(t_data *data, char *line, int *i, int *capacity);
int		init_map(t_data *data, char *line);
int		is_map_closed(t_data *data, int rows, int cols);
int		check_chars_map(t_data *data, int rows, int cols);
void	map_flood(t_data *data, int y, int x);
void	flood_loop(t_data *data, int y, int x);
int		check_map_position(t_data *data, int i, int j);
int     ft_strcmp(const char *s1, const char *s2);
#endif
