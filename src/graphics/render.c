/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:41:34 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/04 18:16:47 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->gfx.height)
	{
		x = 0;
		while (x < game->gfx.width)
		{
			if (y < game->gfx.height / 2)
				put_pixel(&game->image, x, y, game->gfx.hex_ceiling);
			else
				put_pixel(&game->image, x, y, game->gfx.hex_floor);
			x++;
		}
		y++;
	}
}

static void	calculate_height(t_game *game, t_raycast *ray)
{
	ray->line_height = (int)(game->gfx.height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->gfx.height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->gfx.height / 2;
	if (ray->draw_end >= game->gfx.height)
		ray->draw_end = game->gfx.height - 1;
}

static void	calculate_tex_x(t_game *game, t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->tex_num = TEX_E;
		else
			ray->tex_num = TEX_W;
		ray->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->tex_num = TEX_S;
		else
			ray->tex_num = TEX_N;
		ray->wall_x = game->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x
			* (double)game->textures[ray->tex_num].width);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		ray->tex_x = game->textures[ray->tex_num].width - ray->tex_x - 1;
}

static void	draw_stripe(t_game *game, t_raycast *ray, int x)
{
	t_texture	*tex;
	double		step;
	double		tex_pos;
	int			y;
	int			tex_y;

	tex = &game->textures[ray->tex_num];
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - game->gfx.height / 2 + ray->line_height / 2)
		* step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos % tex->height;
		tex_pos += step;
		if (tex_y < 0)
			tex_y += tex->height;
		put_pixel(&game->image, x, y, get_texture_color(tex, ray->tex_x,
				tex_y));
		y++;
	}
}

void	render_frame(t_game *game)
{
	t_raycast	ray;
	int			x;

	draw_floor_ceiling(game);
	x = 0;
	while (x < game->gfx.width)
	{
		init_ray_direction(game, &ray, x);
		init_delta_distance(&ray);
		init_step_and_side_distance(game, &ray);
		perform_dda(game, &ray);
		calc_wall_dist(game, &ray);
		calculate_height(game, &ray);
		calculate_tex_x(game, &ray);
		draw_stripe(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win, game->image.img, 0,
		0);
}
