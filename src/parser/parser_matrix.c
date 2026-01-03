/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:00:50 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/30 19:49:47 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	auxiliary function to determine if a line is part of the map
	Returns 1 if it is a map, 0 if it is junk/texture:
		1. skip leading spaces
		2. if, after the spaces, there is a 1 or a 0, it is part of the map
*/
int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

/*
This is the main function:
1. Count the rows.
2. Allocate memory
   - sizeof(char*) * (height + 1 for the final Null)
3. Use ft_strdup to copy the line into the matrix

	- Here the line is copied exactly as it is (including spaces) because the map needs the spaces to determine its shape.
		We can remove the trailing \n with ft_strtrim or something similar if desired,
			but for the map it’s sometimes better to leave it and handle it later.
		We will use ft_strdup and then, if needed, clean the \n.
4. Manually remove the \n if it exists.
*/
int	create_map_matrix(t_game *game)
{
	t_list	*tmp;
	int		i;
	char	*line_content;
	int		len;

	game->map_height = 0;
	tmp = game->map_list;
	while (tmp)
	{
		if (is_map_line((char *)tmp->content))
			game->map_height++;
		tmp = tmp->next;
	}
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (printf("Error: Malloc map failed\n"), 0);
	i = 0;
	tmp = game->map_list;
	while (tmp)
	{
		if (is_map_line((char *)tmp->content))
		{
			line_content = (char *)tmp->content;
			len = ft_strlen(line_content);
			if (line_content[len - 1] == '\n')
				line_content[len - 1] = '\0';
			game->map[i] = ft_strdup(line_content);
			i++;
		}
		tmp = tmp->next;
	}
	game->map[i] = NULL;
	return (1);
}
