/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:25:29 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/04 09:17:23 by gafreire         ###   ########.fr       */
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

static char	*get_texture(char *line, char *id)
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
	Auxiliar function:
		check missing textures
*/

static int	check_missing_data(t_game *game)
{
	if (!game->tex_north || !game->tex_south || !game->tex_west
		|| !game->tex_east || !game->color_floor || !game->color_ceiling)
		return (printf("Error: Missing texture or color identifier\n"), 0);
	return (1);
}

/*
	Auxiliar function:
		check whether the line matches the ID
		if it does, verify duplicates and save
		‘dest’ is a pointer to the variable 
		in the original struct (&game->variable)
		By modifying ‘dest’, we modify the original variable
*/

static int	check_and_save(char *line, char *id, char **dest)
{
	if (ft_strncmp(line, id, ft_strlen(id)) == 0)
	{
		if (*dest)
			return (printf("Error: Duplicate identifier %s\n", id), -1);
		*dest = get_texture(line, id);
		return (1);
	}
	return (0);
}
/*
	Auxiliar function:
		pass the line through all possible filters
*/

static int	scan_line(t_game *game, char *line)
{
	int	res;

	res = check_and_save(line, "NO", &game->tex_north);
	if (res != 0)
		return (res);
	res = check_and_save(line, "SO", &game->tex_south);
	if (res != 0)
		return (res);
	res = check_and_save(line, "WE", &game->tex_west);
	if (res != 0)
		return (res);
	res = check_and_save(line, "EA", &game->tex_east);
	if (res != 0)
		return (res);
	res = check_and_save(line, "F", &game->color_floor);
	if (res != 0)
		return (res);
	res = check_and_save(line, "C", &game->color_ceiling);
	if (res != 0)
		return (res);
	return (0);
}

/*
	Main function:
		traverse the list and use scan_line to process each line
*/

int	get_map_info(t_game *game)
{
	t_list	*tmp;
	char	*line;
	int		status;

	tmp = game->map_list;
	while (tmp)
	{
		line = (char *)tmp->content;
		if (line[0] == '1' || line[0] == '0')
			break ;
		status = scan_line(game, line);
		if (status == -1)
			return (0);
		tmp = tmp->next;
	}
	if (!check_missing_data(game))
		return (0);
	return (1);
}
