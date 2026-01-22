/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:02:09 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/22 06:06:40 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// intialize ray and calculate distance 

#include "../../include/cubed.h"

void	init_ray_direction(t_game *game, t_raycast *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)game->gfx.width - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->dir_y = game->player.dir_y + game->player.player_y * ray->camera_x;
// scalar value camera_x axis rays casted horizontally across the screen L to R
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->hit = 0;
}

void	init_delta_distance(t_raycast *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->dir_y);
}
// fabs() - single (f)double argument with absolute value
