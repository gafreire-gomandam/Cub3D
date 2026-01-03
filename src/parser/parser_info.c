/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:25:29 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/03 12:21:32 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliary function:
	Receives the complete line (e.g.,
		"NO ./textures/wall.xpm\n") and the identifier (e.g., "NO").
	Returns only the clean path (e.g., "./textures/wall.xpm").
		1. Skip the letters of the identifier (N, O...).
		2. Skip any spaces that follow (e.g., "NO    ./path").
		3. Store the rest in a new copy.
			Use ft_strtrim to remove the trailing newline (\n).
*/

char	*get_texture(char *line, char *id)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (id[i] && line[i] == id[i])
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	tmp = ft_strdup(line + i);
	path = ft_strtrim(tmp, "\n");
	free(tmp);
	return (path);
}

/*
	Main function:
		1. Check what each line is and store it.
			Use ft_strncmp to see if it starts with NO, SO, etc.
		2. If we find a 1, it means the map starts. Stop processing.
*/
int	get_map_info(t_game *game)
{
	t_list	*tmp;
	char	*line;

	tmp = game->map_list;
	while (tmp)
	{
		line = (char *)tmp->content;
		if (ft_strncmp(line, "NO", 2) == 0)
			game->tex_north = get_texture(line, "NO");
		else if (ft_strncmp(line, "SO", 2) == 0)
			game->tex_south = get_texture(line, "SO");
		else if (ft_strncmp(line, "WE", 2) == 0)
			game->tex_west = get_texture(line, "WE");
		else if (ft_strncmp(line, "EA", 2) == 0)
			game->tex_east = get_texture(line, "EA");
		else if (ft_strncmp(line, "F", 1) == 0)
			game->color_floor = get_texture(line, "F");
		else if (ft_strncmp(line, "C", 1) == 0)
			game->color_ceiling = get_texture(line, "C");
		else if (line[0] == '1' || line[0] == '0')
			break ;
		tmp = tmp->next;
	}
	printf("Norte: %s\n", game->tex_north);
	printf("Sur:   %s\n", game->tex_south);
	printf("Oeste: %s\n", game->tex_west);
	printf("Este:  %s\n", game->tex_east);
	printf("Suelo: %s\n", game->color_floor);
	printf("Techo: %s\n", game->color_ceiling);
	return (1);
}
