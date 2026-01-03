/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:46 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/03 12:52:12 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		y;

	if (argc != 2)
		printf("Error arguments\n");
	else
	{
		if (check_map(argv[1]))
		{
			// create struct
			init_game(&game);
			if (parse_game(argv[1], &game))
			{
				// 1. extract textures
				if (!get_map_info(&game)) 
				    return (free_resources(&game),1);
				// 2. extract map
				if (!create_map_matrix(&game))
					return (free_resources(&game), 1);
				// 3. IMPORTANT! The list is no longer valid; convert it to a matrix
				free_list(&game.map_list);
				printf("Checking map contents...\n");
				if (!validate_map_content(&game))
					return (free_resources(&game), 1);
				if (!check_map_closed(&game))
					return (free_resources(&game), 1);
				printf("¡Valid map! Player in (%d, %d) looking %c\n",
					game.player_x, game.player_y, game.player_dir);
				// (DEBUG)
				y = 0;
				printf("\n--- MAP IN ARRAY ---\n");
				while (game.map[y])
				{
					printf("%s\n", game.map[y]);
					y++;
				}
				// 4. at the end general cleanup
				free_resources(&game);
				return (0);
			}
			//  else
			//  {
			//     // free(struct);
			//     return (-1);
			//  }
		}
		else
			return (printf("Exit\n"), -1);
	}
	return (0);
}
