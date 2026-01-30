/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 02:47:56 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/30 00:47:30 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

// For static void fx we can simply include the variables inside the function
// 	instead of making it as arguments. But just in case we need more lines
static void	init_step_x(t_game *game, t_raycast *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
}

static void	init_step_y(t_game *game, t_raycast *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (game->player.pos_y - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	init_step_and_side_distance(t_game *game, t_raycast *ray)
{
	init_step_x(game, ray);
	init_step_y(game, ray);
}
