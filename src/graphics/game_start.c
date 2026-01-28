/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:40:21 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/28 03:39:11 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		Initialize the connection with X11
*/

static void	init_mlx(t_game *game)
{
	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
	{
		printf("Error: MLX init failed\n");
		free_resources(game);
		exit(1);
	}
}
/*
	Auxiliar function:
		Create the graphics window
*/

static void	create_game_window(t_game *game)
{
	game->gfx.win = mlx_new_window(game->gfx.mlx, game->gfx.width,
			game->gfx.height, "Cub3D - The Beginning");
	if (!game->gfx.win)
	{
		printf("Error: MLX window failed\n");
		free_resources(game);
		exit(1);
	}
}
/*
	Main function:
		1. init colors
		2. init mlx and window
		3. create hooks
		4.start loop

*/

void	start_game(t_game *game)
{
	init_colors(game);
	init_mlx(game);
	create_game_window(game);
/* include at .h and these functions */
	// init_colors(game);
	// init_player_position(game);
	// init_player_direction(game);
	// init_player_plane(game);
	mlx_hook(game->gfx.win, ON_KEYDOWN, 1L << 0, key_press, game);
	mlx_hook(game->gfx.win, ON_DESTROY, 0, close_window, game);
	printf("🎨 Window opened! Press ESC to close.\n");
	mlx_loop(game->gfx.mlx);
}
// print to check: player position, direction and plane?
