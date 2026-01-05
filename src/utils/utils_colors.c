/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:45:36 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/05 20:26:09 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliar function:
		converts an array of strings ["220", "100", "0"] to hexadecimal
*/

static unsigned long	rgb_to_hex(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

/*
	Main function:
		1. Split the string into parts
		2. Convert to a hexadecimal number
		3. Store the result in floor / ceiling
		4. Free the temporary memory from the split
*/

int	init_colors(t_game *game)
{
	char	**rgb_f;
	char	**rgb_c;

	rgb_f = ft_split(game->color_floor, ',');
	if (!rgb_f)
		return (0);
	game->gfx.hex_floor = rgb_to_hex(rgb_f);
	free_split(rgb_f);
	rgb_c = ft_split(game->color_ceiling, ',');
	if (!rgb_c)
		return (0);
	game->gfx.hex_ceiling = rgb_to_hex(rgb_c);
	free_split(rgb_c);
	return (1);
}
