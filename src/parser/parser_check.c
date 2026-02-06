/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:42:13 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/06 12:05:08 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliary function:
		check if the characters is allowed
*/

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
	Auxiliary function:
		Checks if the line is a valid configuration identifier (NO, SO, etc.)
*/

static int	is_identifier_line(char *line)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2))
		return (1);
	if (!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (1);
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (1);
	return (0);
}

/*
	Main function:
		1. find where the map starts
		2. if an empty line is found after the map has started, activate a flag
		3. if more map is found while the flag is active, it is an error
		State[0] = map_started, State[1] = space_found (empty line inside map)
*/

int	check_map_spaces(t_game *game)
{
	t_list	*tmp;
	int		state[2];

	state[0] = 0;
	state[1] = 0;
	tmp = game->map_list;
	while (tmp)
	{
		if (is_map_line(tmp->content) && state[1])
			return (printf("Error: Empty line inside map\n"), 0);
		if (is_map_line(tmp->content))
			state[0] = 1;
		else if (state[0] && !is_empty_line(tmp->content))
			return (printf("Error: Content found after map\n"), 0);
		else if (state[0])
			state[1] = 1;
		else if (!is_empty_line(tmp->content)
			&& !is_identifier_line(tmp->content))
			return (printf("Error: Invalid line: %s", (char *)tmp->content), 0);
		tmp = tmp->next;
	}
	if (!state[0])
		return (printf("Error: No map found\n"), 0);
	return (1);
}

/*
	Auxiliar function:
		iterate a specific row
			1. validate each character
			2. if a player is found, update the info 
			   and increase the counter
*/
static int	scan_row(t_game *game, int y, int *players_count)
{
	int	x;
	int	c;

	x = 0;
	while (game->map[y][x])
	{
		c = game->map[y][x];
		if (!is_valid_char(c))
			return (printf("Error: Invalid character '%c' in map\n", c), 0);
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			(*players_count)++;
			game->player_x = x;
			game->player_y = y;
			game->player_dir = c;
		}
		x++;
	}
	return (1);
}
/*
	Main function:
		iterate rows, and for each row, iterate columns (letters):
		1. check valid characters
		2. check player
			- save the postion to use later
		3. final check
*/

int	validate_map_content(t_game *game)
{
	int	i;
	int	players_count;

	players_count = 0;
	i = 0;
	while (game->map[i])
	{
		if (!scan_row(game, i, &players_count))
			return (0);
		i++;
	}
	if (players_count == 0)
		return (printf("Error: Player is missing (N,S,E,W)\n"), 0);
	if (players_count > 1)
		return (printf("Error: Too many players. Only one allowed.\n"), 0);
	return (1);
}
