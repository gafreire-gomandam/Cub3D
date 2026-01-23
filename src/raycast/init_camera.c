/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 01:45:26 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/23 01:52:56 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	rotate_90_ccw(double *x, double *y)
{
	double	temp_x;

	temp_x = *x;
	*x = *y;
	*y = -temp_x;
}

void	init_camera_plane(t_game *game)
{
	game->player.plane_x = game->player.dir_x;
	game->player.plane_y = game->player.dir_y;
	rotate_90_ccw(&game->player.plane_x, &game->player.plane_y);
	game->player.plane_x *= 0.66;
	game->player.plane_y *= 0.66;
}
