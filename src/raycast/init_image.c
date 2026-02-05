/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 02:03:48 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/05 15:39:48 by gomandam         ###   ########.fr       */
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
	game->image.addr = mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel,
			&game->image.line_length,
			&game->image.endian);
}
// allocate off-screen buffer, retrieve direct memory access for pixels
// during game initialization: sets up rendering target
// create MLX image buffer, validate allocations
// mlx_get_data_addr(); gets direct memory address of pixel data
// stores metadata:
// 	bits per pixel, line length (bytes per row), endian = byte order memory
// usage: fast pixel writing

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	offset = y * image->line_length + x * (image->bits_per_pixel / 8);
	pixel = image->addr + offset;
	*(unsigned int *)pixel = color;
}
// put a single pixel to image buffer using direct memory access
// called per frame during rendering (thousands per column)
// y * line_length == row offset in bytes
/* x * (bits_per_pixel / 8) == column offset in bytes 
		(4 bytes per pixel 32-bit color) */
// get pointer to  target pixel memory
// write color value unsigned int (ARGB format)
// used for core rendering: ceiling, floor, wall pixels
