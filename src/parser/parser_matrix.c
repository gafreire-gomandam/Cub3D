/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:00:50 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/03 18:37:23 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliary function:
		to determine if a line is part of the map
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
	Auxiliar function:
		count how many rows the map will have
*/

static int	count_rows(t_list *list)
{
	int	height;

	height = 0;
	while (list)
	{
		if (is_map_line((char *)list->content))
			height++;
		list = list->next;
	}
	return (height);
}

/*
	Auxiliar function:
		create a clean copy of the line (without the final \n)
*/
static char	*save_line(char *s)
{
	char	*copy;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		len--;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
	This is the main function:
		1. Count the rows.
		2. Allocate memory
		   - sizeof(char*) * (height + 1 for the final Null)
		3. traverse the list and copy each valid line 
			into the matrix using save_line
		4. Manually remove the \n if it exists.
*/

int	create_map_matrix(t_game *game)
{
	t_list	*tmp;
	int		i;

	game->map_height = count_rows(game->map_list);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (printf("Error: Malloc map failed\n"), 0);
	i = 0;
	tmp = game->map_list;
	while (tmp)
	{
		if (is_map_line((char *)tmp->content))
		{
			game->map[i] = save_line((char *)tmp->content);
			if (!game->map[i])
				return (printf("Error: Malloc line failed\n"), 0);
			i++;
		}
		tmp = tmp->next;
	}
	game->map[i] = NULL;
	return (1);
}
