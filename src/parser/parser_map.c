/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:54:10 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/05 18:12:34 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Auxiliary function:
		1. Check if filename length is greater than 4
		2. Verify last 4 characters are ".cub"
		3. Return 0 if invalid, 1 if valid
*/

static int	check_file(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len > 4)
	{
		if (ft_strncmp(map + (len - 4), ".cub", 4) != 0)
			return (printf("File invalid\n"), 0);
	}
	else
		return (printf("Not valid map\n"), 0);
	return (1);
}

/*
	Auxiliary function:
		1. Try to open the file in read-only mode
		2. If open fails, return 0
		3. Close file descriptor and return 1 if successful
*/

static int	check_info(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

/*
	Main function:
		1. Validate file has .cub extension
		2. Verify file can be opened
		3. Return 0 if any check fails, 1 if all pass
*/

int	check_map(char *map)
{
	if (!check_file(map))
		return (0);
	if (!check_info(map))
		return (printf("Error open\n"), 0);
	return (1);
}
