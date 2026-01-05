/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:38:08 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/05 20:00:13 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Hook : close window
		- It is called when you click
			the window’s close button (the X)
		- It closes the program cleanly (without leaks)
*/

int	close_window(t_game *game)
{
	printf("Window closed. Exiting...\n");
	free_resources(game);
	exit(0);
	return (0);
}
/*
	Hook: key press
		It is called when the ESC key is pressed
*/

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}
