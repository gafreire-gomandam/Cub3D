/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:54:06 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/05 20:58:48 by gafreire         ###   ########.fr       */
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
		free split
*/

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
/*
	Tool 4:
		free mlx
*/

static void	free_graphics(t_game *game)
{
	if (game->gfx.win)
		mlx_destroy_window(game->gfx.mlx, game->gfx.win);
	if (game->gfx.mlx)
	{
		mlx_destroy_display(game->gfx.mlx);
		free(game->gfx.mlx);
	}
}

/*
	Tool 4:
		free all
		1. free textures and colors
		2. free matrix
		3. free list
		4. free mlx
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
	free_graphics(game);
	return (1);
}
