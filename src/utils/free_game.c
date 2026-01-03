/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:54:06 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/03 12:39:56 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Tool 1:
		free matrix
*/
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/*
	Tool 2:
		free list
*/

void	free_list(t_list **list)
{
	t_list	*temp;
	t_list	*next_node;

	if (!list || !*list)
		return ;
	temp = *list;
	while (temp)
	{
		next_node = temp->next;
		if (temp->content)
			free(temp->content);
		free(temp);
		temp = next_node;
	}
	*list = NULL;
}

/*
	Tool 3:
		free all
		1. free textures and colors
		2. free matrix
		3. free list
		4.
*/
int	free_resources(t_game *game)
{
	if (game->tex_north)
		free(game->tex_north);
	if (game->tex_south)
		free(game->tex_south);
	if (game->tex_west)
		free(game->tex_west);
	if (game->tex_east)
		free(game->tex_east);
	if (game->color_floor)
		free(game->color_floor);
	if (game->color_ceiling)
		free(game->color_ceiling);
	if (game->map)
		free_matrix(game->map);
	if (game->map_list)
		free_list(&game->map_list);
	// MLX cleanup will be done here later…
	return (1);
}
