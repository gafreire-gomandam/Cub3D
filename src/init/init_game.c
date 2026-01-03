/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:41:17 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/03 12:57:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_game(t_game *game)
{
	game->map_list = NULL;
	game->tex_north = NULL;
	game->tex_south = NULL;
	game->tex_west = NULL;
	game->tex_east = NULL;
	game->color_floor = NULL;
	game->color_ceiling = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_dir = 0;
}
