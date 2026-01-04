/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:47:27 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/04 09:48:47 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		checks whether a line contains only spaces,
		tabs, or newline characters
*/

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
	Auxiliar function:
		1. if it is empty: free it and return success
		2. if it has content: create a node and add it to the list
*/

static int	process_line(t_game *game, char *line)
{
	t_list	*new_node;

	if (is_empty_line(line))
		return (free(line), 1);
	new_node = ft_lstnew(line);
	if (!new_node)
	{
		free(line);
		return (printf("Error: Malloc failed adding node\n"), 0);
	}
	ft_lstadd_back(&game->map_list, new_node);
	return (1);
}

/*
	Main function:
		open the .cub file and read it line by line using gnl
		save the relevant lines in a linked list to process them later
*/

int	parse_game(char *map, t_game *game)
{
	int		fd;
	char	*line;

	game->map_list = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (printf("Error: Could not open map file\n"), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!process_line(game, line))
			return (close(fd), 0);
	}
	close(fd);
	return (1);
}
