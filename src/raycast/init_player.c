/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 04:06:26 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/28 22:57:33 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Initialize player vector in the map

#include "cubed.h"

void	init_player_position(t_game *game)
{
	game->player.pos_x = (double)game->player_x + 0.5;
	game->player.pos_y = (double)game->player_y + 0.5;
}

void	init_player_direction(t_game *game)
{
	if (game->player_dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	else if (game->player_dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	else if (game->player_dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
	}
	else if (game->player_dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
}
