/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:02:27 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/04 04:27:09 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// steps, perform DDA, check for hits. Distance ray travels between grid lines

#include "../../include/cubed.h"

static int	check_wall_hit(t_game *game, t_raycast *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->map_height)
		return (1);
	if (ray->map_x < 0 || ray->map_x >= (int)ft_strlen(game->map[ray->map_y]))
		return (1);
	if (game->map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

// check_wall_hit() validates grid bounds/range and detect wall collision
// map_y vertical bound, map_x row length
// check current cell is a wall '1' and return(0) if no wall detected
// usage: called after each ray step to determine wall hits

static void	step_ray(t_raycast *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

// advance ray one cell, x or y dir. called repeatedly until wall hits
// if (ray->side_dist_x < ray->side_dist_y) -> check if x-side is closer than y-side
// advance to x-side, move to next cell/grid, mark hit as vertical side = 0
// else () step in y-dir, mark horizontal side = 1

void	perform_dda(t_game *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		step_ray(ray);
		if (check_wall_hit(game, ray))
			ray->hit = 1;
	}
}

// Digital differential analysis algorithm
// called per screen column during raycasting
// while() loop until wall is detected
// step the ray by one grid cell, check for wall and set hit flag if found
// usage: main raycasting loop 
