/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:42:18 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/05 17:09:54 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliary function:
		1. Apply 2D rotation matrix to direction vector
		2. Apply same rotation to camera plane vector
		3. Both vectors rotate by rotspeed (in radians)
*/

void	rotate_player(t_game *game, double rotspeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotspeed) - game->player.dir_y
		* sin(rotspeed);
	game->player.dir_y = old_dir_x * sin(rotspeed) + game->player.dir_y
		* cos(rotspeed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotspeed)
		- game->player.plane_y * sin(rotspeed);
	game->player.plane_y = old_plane_x * sin(rotspeed) + game->player.plane_y
		* cos(rotspeed);
}

/*
	Auxiliary function:
		1. Check X movement independently for collision
		2. Check Y movement independently for collision
		3. Update position only if not hitting a wall
*/

void	move_player(t_game *game, double move_x, double move_y)
{
	int	new_x;
	int	new_y;

	new_x = (int)(game->player.pos_x + move_x);
	new_y = (int)(game->player.pos_y);
	if (game->map[new_y][new_x] != '1')
		game->player.pos_x += move_x;
	new_x = (int)(game->player.pos_x);
	new_y = (int)(game->player.pos_y + move_y);
	if (game->map[new_y][new_x] != '1')
		game->player.pos_y += move_y;
}
