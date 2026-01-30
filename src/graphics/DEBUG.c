/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:59:50 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/30 01:35:34 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	print_ray_info(int x, t_raycast *ray)
{
	printf("Ray[%3d]: dir(%.2f, %.2f) distance=%.2f side=%d\n", 
			x, ray->dir_x, ray->dir_y, ray->perp_wall_dist, ray->side);
}

void	test_single_ray(t_game *game, int screen_x)
{
	t_raycast	ray;

	printf("\n *** TESTING single ray at x=%d *** \n", screen_x);
	init_ray_direction(game, &ray, screen_x);	// test
	printf(" *** Camera x: %.3f\n", ray.camera_x);
	printf("Ray Dir: (%.3f, %.3f)\n", ray.dir_x, ray.dir_y);
	init_delta_distance(&ray);			// test
	printf("Delta: (%.3f, %.3f)\n", ray.delta_dist_x, ray.delta_dist_y);
	init_step_and_side_distance(game, &ray);	// test
	printf("Step: (%d, %d)\n", ray.step_x, ray.step_y);
	printf("Side Dist: (%.3f, %.3f)\n", ray.side_dist_x, ray.side_dist_y);
	perform_dda(game, &ray);			// test
	printf("Hit at: [%d, %d]\n", ray.map_x, ray.map_y);
	calc_wall_dist(game, &ray);			// test
	printf("Wall Distance: %.3f (side %d)\n\n", ray.perp_wall_dist, ray.side);
}

void	test_raycast_sweep(t_game *game)
{
	t_raycast	ray;
	int		x;
	int		step;

	printf("\n\n *** RAYCAST TEST *** \n");
	printf("Player: (%.2f, %.2f) Direction: (%.2f, %.2f)\n",
			game->player.pos_x, game->player.pos_y,
			game->player.dir_x, game->player.pos_y);
	step = game->gfx.width / 10;
	x = 0;
	while (x < game->gfx.width)
	{
		init_ray_direction(game, &ray, x);
		init_delta_distance(&ray);
		init_step_and_side_distance(game, &ray);
		perform_dda(game, &ray);
		calc_wall_dist(game, &ray);
		print_ray_info(x, &ray);
		x += step;
	}
	printf("\n END...\n\n");
}

