/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:02:09 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/22 03:11:39 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// intialize ray and calculate distance 

#include "cubed.h"

void	init_ray_direction(t_game *game, t_raycast *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)game->gfx.width - 1.0;
	ray->dir_x
	ray->dir_y
	ray->map_x
	ray->map_y
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
