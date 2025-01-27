/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:23:12 by bastienverd       #+#    #+#             */
/*   Updated: 2024/11/25 12:32:45 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "parsing.h"
# include "struct.h"
# include "utils.h"
# include "library.h"
# include "graphics.h"

# define WINWIDTH 100
# define WINHEIGHT 100
# define WINNAME "love death & robots"

# define ARG "Too many or not enough arguments"
# define MALLOC "malloc failed"

# define FILE_ISDIR "Argument is a directory, not a file"
# define FILE_DE "File doesn't exist"
# define FILE_INVE "Filename or extension is invalid"

# define MISSING_COORD "Missing or invalid coordinates"
# define MISSING_TPATH "Missing texture path"
# define MISSING_COLOR "Missing color"

# define RGB_FORMAT "The colour isn't in the rgb format"
# define COLOUR_FORMAT "The colour line isn't formatted properly"

# define MAP_OPEN "Map not closed"
# define MAP_BIG "Map size is too big"
# define MAP_NL "newline in map"

# define INV_CHAR_TXT  "Invalid character/s in texture path"
# define INV_CHAR "Invalid Character/s in the map"
# define NO_PLAYER "Player not found"
# define PLAYER_NUM "More than one player found in the map"

#endif
