/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:52:19 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/05 20:27:22 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>

# define KEY_ESC 65307

# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct s_gfx
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;

	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
}					t_gfx;

typedef struct s_game
{
	t_list			*map_list;
	char			*tex_north;
	char			*tex_south;
	char			*tex_west;
	char			*tex_east;

	char			*color_floor;
	char			*color_ceiling;

	char			**map;
	int				map_height;

	int				player_x;
	int				player_y;
	char			player_dir;

	t_gfx			gfx;
}					t_game;

// src/parser/parser_map
int					check_map(char *map);
// src/parser/parser_game
int					parse_game(char *map, t_game *game);
int					is_empty_line(char *line);
// src/parser/parser_info
int					get_map_info(t_game *game);

// src/parser/parser_matrix
int					create_map_matrix(t_game *game);
int					is_map_line(char *line);

// src/parser/parser_check
int					validate_map_content(t_game *game);
int					check_map_spaces(t_game *game);

// src/parser/parser_flood
int					check_map_closed(t_game *game);

// src/parser/parser_verify
int					verify_identifiers(t_game *game);

// src/init
void				init_game(t_game *game);

// src/utils/free_game
void				free_list(t_list **list);
void				free_split(char **split);
void				free_matrix(char **matrix);
int					free_resources(t_game *game);

// src/graphics/game_start
void				start_game(t_game *game);

// src/graphics/game_hooks
int					close_window(t_game *game);
int					key_press(int keycode, t_game *game);

// srcr/utils/utils_colors
int					init_colors(t_game *game);

#endif