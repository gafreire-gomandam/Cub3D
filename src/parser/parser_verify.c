/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:45:38 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/03 18:48:30 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		check if a string contains only digits
		1. skip spaces at the beginning (e.g., ‘ 220’)
		2. check if the string is empty
*/

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
/*
	Auxiliar function:
		validate that the 3 values in the RGB array are correct (0–255)	
*/

static int	validate_rgb_values(char **rgb)
{
	int	i;
	int	num;

	i = 0;
	while (rgb[i])
	{
		if (!is_numeric(rgb[i]))
			return (printf("Error: Color contains non-numeric chars\n"), 0);
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (printf("Error: Color value out of range (0-255)\n"), 0);
		i++;
	}
	return (1);
}

/*
	Auxiliar function:
		validate colors (R,G,B)
		verify: 3 numbers, between 0 and 255, digits only
		1. split by commas
		2. count that there are exactly 3 parts
		3. call auxiliar function validate_rgb_values
*/

static int	check_color_format(char *color_str, char *type)
{
	char	**rgb;
	int		i;

	rgb = ft_split(color_str, ',');
	if (!rgb)
		return (printf("Error: Malloc failed in color check\n"), 0);
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free_split(rgb);
		return (printf("Error: Invalid format for %s (Must be R,G,B)\n", type),
			0);
	}
	if (!validate_rgb_values(rgb))
	{
		free_split(rgb);
		return (0);
	}
	free_split(rgb);
	return (1);
}

/*
	Auxiliar function:
		verify textures
		attempts to open the file
		1. check that the extension is .xpm
		2. check if the file exists
*/

static int	check_texture_file(char *path, char *name)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (printf("Error: Texture %s must be .xpm\n", name), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Error: Cannot open texture file %s\n", path), 0);
	close(fd);
	return (1);
}
/*
	Main function:
		1. verify textures
		2. verify colors
*/

int	verify_identifiers(t_game *game)
{
	if (!check_texture_file(game->tex_north, "NO"))
		return (0);
	if (!check_texture_file(game->tex_south, "SO"))
		return (0);
	if (!check_texture_file(game->tex_west, "WE"))
		return (0);
	if (!check_texture_file(game->tex_east, "EA"))
		return (0);
	if (!check_color_format(game->color_floor, "Floor"))
		return (0);
	if (!check_color_format(game->color_ceiling, "Ceiling"))
		return (0);
	return (1);
}
