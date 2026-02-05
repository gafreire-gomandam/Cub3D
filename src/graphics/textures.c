/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:40:01 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/05 17:55:44 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliary function:
		1. Load XPM file into image
		2. Get pixel data address
		3. If fails, free and exit
*/

static void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->gfx.mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		printf("Error: Failed to load texture: %s\n", path);
		free_resources(game);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}

/*
	Auxiliary function:
		1. Load all four wall textures
		2. Store them in textures array (N, S, E, W)
*/

void	init_textures(t_game *game)
{
	load_texture(game, &game->textures[TEX_N], game->tex_north);
	load_texture(game, &game->textures[TEX_S], game->tex_south);
	load_texture(game, &game->textures[TEX_E], game->tex_east);
	load_texture(game, &game->textures[TEX_W], game->tex_west);
}

/*
	Auxiliary function:
		1. Check if coordinates are within texture bounds
		2. Calculate pixel position in memory
		3. Return color value (0 if out of bounds)
*/

int	get_texture_color(t_texture *tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
