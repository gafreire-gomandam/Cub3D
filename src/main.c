/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:46 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/30 00:57:43 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		1. extract textures
		2. verify that they exist
		3. create the map matrix
		4. clean the list (no longer needed)
		5. validate content and perform flood fill
*/

static int	load_map_data(t_game *game)
{
	if (!get_map_info(game))
		return (0);
	if (!verify_identifiers(game))
		return (0);
	if (!check_map_spaces(game))
		return (0);
	if (!create_map_matrix(game))
		return (0);
	free_list(&game->map_list);
	if (!validate_map_content(game))
		return (0);
	if (!check_map_closed(game))
		return (0);
	return (1);
}
/*
	Main function:
		1. check arguments.
		2. check file.
		3. initial reading (parse_game).
		4. data processing (load_map_data)
		5. start game
*/

/* DEBUGGING: test from copilot at graphics/game_start.c */


int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (printf("Error: Invalid arguments\n"), 1);
	if (!check_map(argv[1]))
		return (1);
	init_game(&game);
	if (!parse_game(argv[1], &game))
		return (free_resources(&game), 1);
	if (!load_map_data(&game))
		return (free_resources(&game), 1);
	printf("Map loaded successfully! Launching Game...\n");
	start_game(&game);
	free_resources(&game);
	return (0);
}
