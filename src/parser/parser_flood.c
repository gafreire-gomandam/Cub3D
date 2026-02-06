/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flood.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:19:01 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/06 10:47:08 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		Copy the entire map to modify it without altering the original
*/

static char	**duplicate_map(t_game *game)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (game->map[i])
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (!new_map[i])
			return (free_matrix(new_map), NULL);
		i++;
	}
	return (new_map);
}

/*
	Recursive Algorithm:
		returns 1 if it is closed, 0 if there is a leak
		1. leak Condition: out of bound (x < 0, y < 0, etc)
		2. if we reach an empty space
		3. stop condition: if it is a wall (1) or we have already been here (V)
		4. mark the cell as visited (V) so we don’t check it again
		5. we traverse the 4 directions: if any directions fails (returns 0),
			the everthing fails
		6. rigth, left, down, up
*/

static int	flood_fill(char **map, int x, int y, int height)
{
	if (y < 0 || y >= height || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	map[y][x] = 'V';
	if (flood_fill(map, x + 1, y, height) == 0)
		return (0);
	if (flood_fill(map, x - 1, y, height) == 0)
		return (0);
	if (flood_fill(map, x, y + 1, height) == 0)
		return (0);
	if (flood_fill(map, x, y - 1, height) == 0)
		return (0);
	return (1);
}

/*
	Main function:
	1. create copy
	2. execute flood fill from the player position:
		we use the coordinates saved in the previous step (parser_check)
	3. free copy
*/

int	check_map_closed(t_game *game)
{
	char	**temp_map;
	int		result;

	temp_map = duplicate_map(game);
	if (!temp_map)
		return (printf("Error: Malloc failed in flood fill\n"), 0);
	result = flood_fill(temp_map, game->player_x, game->player_y,
			game->map_height);
	free_matrix(temp_map);
	if (result == 0)
		return (printf("Error: The map is not closed \n"), 0);
	return (1);
}
