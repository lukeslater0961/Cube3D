/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:35:16 by bastienverd       #+#    #+#             */
/*   Updated: 2024/11/14 16:26:33 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int		print_error(char *str);
void	skip_newline(char **line, t_data *data);
int		free_tab_print_err(char *str, char **tab);
char	**ft_double_split(char const *s, char c, char c2);
int		process_line(char **line);
int		check_for_player(char c, t_data *data, int i, int j);
char	*remove_spaces_tabs(char *str);
int		is_newline(char *line);
int		check_value_range(char *str, char **rgb);
void	process_short_lines(t_data *data);

#endif
