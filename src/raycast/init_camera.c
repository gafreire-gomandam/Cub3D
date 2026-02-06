/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 01:45:26 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/06 15:11:03 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	rotate_90_ccw(double *x, double *y)
{
	double	temp_x;

	temp_x = *x;
	*x = -(*y);
	*y = temp_x;
}

// rotate 2D vector 90 deg. CCW
// store original x in temporary, x becomes negative y (rotated)
// y becomes old x (completes the rotation).
/*	DERIVATION:
 		since, cos(90) = 0, sin(90) = 1
 		new_x = x * cos(90°) - y * sin(90°) --> new_x = -y;
 		new_y = x * sin(90°) + y * cos(90°) --> new_y = x;	*/

void	init_camera_plane(t_game *game)
{
	game->player.plane_x = game->player.dir_x;
	game->player.plane_y = game->player.dir_y;
	rotate_90_ccw(&game->player.plane_x, &game->player.plane_y);
	game->player.plane_x *= 0.66;
	game->player.plane_y *= 0.66;
}

// constructs camera plane perpendicular to player direction FOV
// copy direction vector to plane vector -> player.plane (x,y) to player.dir_ (x,y)
// rotate plane 90 deg. to make it perpendicular
// scale plane to 0.66 FOV == larger->fisheye, smaller->narrow tunnel vision
// usage: setups camera raycasting. plane width determines FOV
/*
	direction: forward view where player faces
	plane: perpendicular to direction (screen Left-Right) enables side ray sweep
	0.66 controls viewing angle
*/
