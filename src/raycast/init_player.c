/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 04:06:26 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/04 17:12:57 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Initialize player vector in the map

#include "cubed.h"

void	init_player_position(t_game *game)
{
	game->player.pos_x = (double)game->player_x + 0.5;
	game->player.pos_y = (double)game->player_y + 0.5;
}
// converts grid coordinates to floating points. init_game(); after map parse
// converts grid (x,y) to float (x,y). 0.5 to center player in cell
// establishes player spawn point in continuous space

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
// set direction vector based on map character (NSEW)
// magnitude formula (vector) = sqrt(dir_x * dir_x + dir_y * dir_y);
