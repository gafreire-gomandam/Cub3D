/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:02:18 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/04 04:10:31 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	calc_wall_dist(t_game *game, t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
				+ (1 - ray->step_x) / 2.0) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
				+ (1 - ray->step_y) / 2.0) / ray->dir_y;
	if (ray->perp_wall_dist < 0.0001)
		ray->perp_wall_dist = 0.0001;
}

// Checks for horizontal or vertical side. vertical 0, horizontal  1
// map_x on the grid where wall hit, while player.pos_x is the starting point
// (1 - step_x) / 2 == if step_x 1 move right, -1 move left (distance to L or R)
// map_y == step_y = 1 distance to top face, step_y = -1 distance to bottom face
// if (ray->perp_wall_dist < 0.0001) ensures safe distance value for rendering.
// 	prevent division by zero, distorts when player touches wall
