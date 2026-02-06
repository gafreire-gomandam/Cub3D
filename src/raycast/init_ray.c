/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:02:09 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/05 15:47:08 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	init_ray_direction(t_game *game, t_raycast *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)game->gfx.width - 1.0;
	ray->dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	ray->hit = 0;
}
// intialize ray and calculate distance 
// calculate ray direction for screen column x. interpolation camera plane edges
// scalar value camera_x axis rays casted horizontally across the screen L to R
// screen pixel x to camera space 
// compute ray direction by adding scaled plane vector to direction
// initialize ray start (player's current position), & then reset wall hit flag

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
// calculates distance ray travels between grid lines (X,Y) axes
// called once per ray after initializing direction
/* dir_x == 0; ray never crosses vertical grid lines
			set to 1e30 to avoid division by zero */
// fabs() - single (f)double argument with absolute value
// calculate x-axis delta distance; distance to travel 1 grid cell horizontally
// 			then do it again for Y-axis
// usage: for DDA algorithm to efficiently step through grid
