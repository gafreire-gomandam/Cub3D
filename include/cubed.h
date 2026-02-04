/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 04:14:20 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/04 18:18:50 by gafreire         ###   ########.fr       */
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
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

# define ON_KEYDOWN 2
# define ON_DESTROY 17

# define TEX_N 0
# define TEX_S 1
# define TEX_E 2
# define TEX_W 3

typedef struct s_texture {
	void    *img;
	char    *addr;
	int     width;
	int     height;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
} 			t_texture;

typedef struct s_gfx
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
}					t_gfx;

// write all pixels to memory. off screen buffer
typedef struct s_image
{
	void	*img;	// MLX image
	char	*addr;	// Direct memory address of pixel data
	int		bits_per_pixel; // Color depth 32-bits
	int		line_length;	// Bytes per row
	int		endian;		// Byte order color encoding
}					t_image;

typedef struct s_player
{
	double	pos_x;	// Player X position in map grid
	double	pos_y;	// Player Y position
	double	dir_x;	// Direction vector X
	double	dir_y;	// Direction vector Y
	double	plane_x;	// Camera plane X (perpendicular to dir)
	double	plane_y;	// Camera plane Y
}					t_player;

typedef struct s_game
{
	t_list			*map_list;
	char			*tex_north;
	char			*tex_south;
	char			*tex_west;
	char			*tex_east;

	char			*color_floor;
	char			*color_ceiling;

	t_texture		textures[4];
	char			**map;
	int				map_height;

	int				player_x;
	int				player_y;
	char			player_dir;
	t_player		player;
	t_image			image;
	t_gfx			gfx;
}					t_game;

typedef struct s_raycast
{
	double	camera_x;	// x coordinate in camera space [-1, 1]
	double	dir_x;		// ray direction x
	double	dir_y;		// ray direction y
	int		map_x;		// current map square x
	int		map_y;		// current map square y
	double	side_dist_x;	// distance to next x-side
	double	side_dist_y;	// distance to next y-side
	double	delta_dist_x;	// distance between x-side
	double	delta_dist_y;	// distance between y-side
	int		step_x;		// step direction x (-1 or 1)
	int		step_y;		// step direction y
	int		hit;		// wall hit flag
	int		side;		// wall side hit (0=NS, 1=EW)
	double	perp_wall_dist;	// perpendicular distance to wall
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
}	t_raycast;

// src/parser/parser_map
/*int					check_map(char *map);
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

// src/utils/utils_colors
int					init_colors(t_game *game);

// RAYCASTING	
// player initialization	
void				init_player_position(t_game *game);
void				init_player_direction(t_game *game);

// camera plane
void				init_camera_plane(t_game *game);

// ray direction and distance
void				init_ray_direction(t_game *game, t_raycast *ray, int x);
void				init_delta_distance(t_raycast *ray);

// step initialization
void				init_step_and_side_distance(t_game *game, t_raycast *ray);

// digital differential analysis algorithm
void				perform_dda(t_game *game, t_raycast *ray);

// walls
void				calc_wall_dist(t_game *game, t_raycast *ray);

// image initialization
void				init_image(t_game *game);
void				put_pixel(t_image *image, int x, int y, int color);

// ****************** DEBUGGING ******************
void				test_raycast_sweep(t_game *game);
void				test_single_ray(t_game *game, int screen_x);
*/

/* --- PARSING (Lectura y Validación del Mapa) --- */
// src/parser/parser_game.c
int     parse_game(char *map, t_game *game);
int     is_empty_line(char *line);

// src/parser/parser_map.c
int     check_map(char *map);

// src/parser/parser_info.c
int     get_map_info(t_game *game);

// src/parser/parser_verify.c
int     verify_identifiers(t_game *game);

// src/parser/parser_check.c
int     check_map_spaces(t_game *game);
int     validate_map_content(t_game *game);

// src/parser/parser_matrix.c
int     create_map_matrix(t_game *game);
int     is_map_line(char *line);

// src/parser/parser_flood.c
int     check_map_closed(t_game *game);

/* --- INICIALIZACIÓN Y MEMORIA --- */
// src/init/init_game.c
void    init_game(t_game *game);

// src/utils/free_game.c
void    free_list(t_list **list);
void    free_split(char **split);
void    free_matrix(char **matrix);
int     free_resources(t_game *game);

// src/utils/utils_colors.c
int     init_colors(t_game *game);

/* --- GRÁFICOS Y EVENTOS (Core) --- */
// src/graphics/game_start.c
void    start_game(t_game *game);

// src/graphics/game_hooks.c
int     close_window(t_game *game);
int     key_press(int keycode, t_game *game);

// src/graphics/render.c (NUEVO v2.0.0)
void    render_frame(t_game *game);

/* --- TEXTURAS (NUEVO v2.0.0) --- */
// src/graphics/textures.c
void    init_textures(t_game *game);
int     get_texture_color(t_texture *tex, int x, int y);

/* --- MOVIMIENTO (NUEVO v2.0.0) --- */
// src/graphics/player_movement.c
void    move_player(t_game *game, double move_x, double move_y);
void    rotate_player(t_game *game, double rotspeed);

/* --- RAYCASTING (Motor Matemático) --- */
// src/raycast/init_player.c
void    init_player_position(t_game *game);
void    init_player_direction(t_game *game);

// src/raycast/init_camera.c
void    init_camera_plane(t_game *game);

// src/raycast/init_ray.c
void    init_ray_direction(t_game *game, t_raycast *ray, int x);
void    init_delta_distance(t_raycast *ray);

// src/raycast/init_steps.c
void    init_step_and_side_distance(t_game *game, t_raycast *ray);

// src/raycast/dda_step.c
void    perform_dda(t_game *game, t_raycast *ray);

// src/raycast/calc_wall_dist.c
void    calc_wall_dist(t_game *game, t_raycast *ray);

/* --- IMAGEN Y PIXELES --- */
// src/raycast/init_image.c
void    init_image(t_game *game);
void    put_pixel(t_image *image, int x, int y, int color);

/* --- DEBUGGING (Opcional, si mantienes DEBUG.c) --- */
void    test_raycast_sweep(t_game *game);
void    test_single_ray(t_game *game, int screen_x);

#endif
