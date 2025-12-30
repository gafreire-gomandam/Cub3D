/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:46 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/30 19:10:03 by gafreire         ###   ########.fr       */
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
				get_map_info(&game);      // 1. Sacamos texturas
				create_map_matrix(&game); // 2. Sacamos el mapa
											// IMPRIMIR PARA COMPROBAR (DEBUG)
				y = 0;
				printf("\n--- MAPA EN MATRIZ ---\n");
				while (game.map[y])
				{
					printf("%s\n", game.map[y]);
					y++;
				}
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
