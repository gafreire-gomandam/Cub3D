/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:54:10 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/02 13:41:43 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	check_file(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len > 4)
	{
		if (ft_strncmp(map + (len - 4), ".cub", 4) != 0 && ft_strncmp(map + (len
					- 4), ".xpm", 4) != 0) // delete xpm
			return (printf("File invalid\n"),
				0);                                                      
				// change function
	}
	else
		return (printf("Not valid map\n"), 0);
	return (1);
}

static int	check_info(char *map) // change name function
{
	int fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);

	close(fd);
	return (printf("Open file\n"), 1);
}

int	check_map(char *map)
{
	if (!check_file(map))
		return (0);
	if (!check_info(map))
		return (printf("Error open\n"), 0);
	return (1);
}
