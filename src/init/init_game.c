/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:41:17 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/03 19:05:09 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		it only initializes the graphics sub-structure (t_gfx)
		the default window size is also set
*/

static void	init_graphics(t_gfx *gfx)
{
	gfx->mlx = NULL;
	gfx->win = NULL;
	gfx->width = 1024;
	gfx->height = 768;
	gfx->hex_floor = 0;
	gfx->hex_ceiling = 0;
}

/*
	Auxiliar function:
		initialize the parser pointers to NULL to avoid trash
*/

static void	init_parser_vars(t_game *game)
{
	game->map_list = NULL;
	game->tex_north = NULL;
	game->tex_south = NULL;
	game->tex_west = NULL;
	game->tex_east = NULL;
	game->color_floor = NULL;
	game->color_ceiling = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_dir = 0;
}


/*
	Auxiliar function:
		Initialize the texture array to NULL.
*/

static void	init_textures_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures[i].img = NULL;
		game->textures[i].addr = NULL;
		game->textures[i].width = 0;
		game->textures[i].height = 0;
		i++;
	}
}

/*
	Main function:
		calls the specific initializations
*/

void	init_game(t_game *game)
{
	init_parser_vars(game);
	init_graphics(&game->gfx);
	game->image.img = NULL;
	game->image.addr = NULL;
	init_textures_struct(game);
}
