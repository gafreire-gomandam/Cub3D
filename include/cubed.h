/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 04:14:20 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/15 16:40:48 by gomandam         ###   ########.fr       */
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

typedef struct s_player
{
	double	pos_x;	// Player X position in map grid
	double	pos_y;	// Player Y position
	double	dir_x;	// Direction vector X
	double	dir_y;	// Direction vector Y
	double	plane_x;	// Camera plane X (perpendicular to dir)
	double	plane_y;	// Camera plane Y
}	t_player;

typedef struct s_raycast
{
	double	camera_x;	// x coordinate in camera space [-1, 1]
	double	dir_x;		// ray direction x
	double	dir_y;		// ray direction y
	int	map_x;		// current map square x
	int	map_y;		// current map square y
	double	side_dist_x;	// distance to next x-side
	double	side_dist_y;	// distance to next y-side
	double	delta_dist_x;	// distance between x-side
	double	delta_dist_y;	// distance between y-side
	int	step_x;		// step direction x (-1 or 1)
	int	step_y;		// steo direction y
	int	hit;		// wall hit flag
	int	side;		// wall side hit (0=NS, 1=EW)
	double	perp_wall_dist;	// perpendicular distance to wall
}	t_raycast

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
