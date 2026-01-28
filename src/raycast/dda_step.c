/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:02:27 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/28 23:06:54 by gomandam         ###   ########.fr       */
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

void	perform_dda(t_game *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		step_ray(ray);
		if (check_wall_hit(game, ray))
			ray->hit = 1;
	}
}
