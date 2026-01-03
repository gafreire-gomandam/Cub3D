/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:52:19 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/30 16:45:21 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_game
{
	t_list	*map_list;
	// .... add more things here later (player,textres,etc....)
}			t_game;

int			check_map(char *map);
int			parse_game(char *map, t_game *game);

#endif