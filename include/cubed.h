/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:52:19 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/04 11:39:17 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_game
{
	t_list	*map_list;
	char	*tex_north;
	char	*tex_south;
	char	*tex_west;
	char	*tex_east;

	char	*color_floor;
	char	*color_ceiling;

	char	**map;
	int		map_height;

	int		player_x;
	int		player_y;
	char	player_dir;
}			t_game;

// src/parser/parser_map
int			check_map(char *map);
// src/parser/parser_game
int			parse_game(char *map, t_game *game);
int			is_empty_line(char *line);
// src/parser/parser_info
int			get_map_info(t_game *game);

// src/parser/parser_matrix
int			create_map_matrix(t_game *game);
int			is_map_line(char *line);

// src/parser/parser_check
int			validate_map_content(t_game *game);
int			check_map_spaces(t_game *game);

// src/parser/parser_flood
int			check_map_closed(t_game *game);

// src/parser/parser_verify
int			verify_identifiers(t_game *game);

// src/init
void		init_game(t_game *game);

void		free_list(t_list **list);
void		free_split(char **split);
void		free_matrix(char **matrix);
int			free_resources(t_game *game);

#endif