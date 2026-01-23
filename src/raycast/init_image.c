/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 02:03:48 by gomandam          #+#    #+#             */
/*   Updated: 2026/01/23 02:43:20 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	init_image(t_game *game)
{
	game->image.img = mlx_new_image(game->gfx.mlx, game->gfx.width,
			game->gfx.height);
	if (!game->image.img)
	{
		printf("Error: MLX image creation failure.\n");
		free_resources(game);
		exit(1);
	}
	game->image.addr = mlx_get_data_addr(game->iamge.img,
			&game->image.bits_per_pixel,
			&game->image.line_length,
			&game->image.endian);
}
// update minilibx directory

void	put_pixel(t_img *image, int x, int y,)
{
	char	*pixel;
	int	offset;

	offset = y * image->line_length + x * (image->bits_per_pixel / 8);
	pixel = img->addr + offset;
	*(unsigned int *)pixel = color;
}
