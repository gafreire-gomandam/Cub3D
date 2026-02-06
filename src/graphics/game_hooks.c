/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:38:08 by gafreire          #+#    #+#             */
/*   Updated: 2026/02/06 14:09:56 by gafreire         ###   ########.fr       */
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
		Activa el movimiento
*/

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		game->key_w = 1;
	else if (keycode == KEY_S)
		game->key_s = 1;
	else if (keycode == KEY_A)
		game->key_a = 1;
	else if (keycode == KEY_D)
		game->key_d = 1;
	else if (keycode == KEY_LEFT)
		game->key_left = 1;
	else if (keycode == KEY_RIGHT)
		game->key_right = 1;
	return (0);
}

/*
	Hook: key release
		Desactiva el movimiento
*/

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_w = 0;
	else if (keycode == KEY_S)
		game->key_s = 0;
	else if (keycode == KEY_A)
		game->key_a = 0;
	else if (keycode == KEY_D)
		game->key_d = 0;
	else if (keycode == KEY_LEFT)
		game->key_left = 0;
	else if (keycode == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}
/*
	Auxiliar function:
		It only processes linear motion (WASD)
*/

static int	process_movement(t_game *game)
{
	if (game->key_w)
		move_player(game, game->player.dir_x * MOVE_SPEED, game->player.dir_y
			* MOVE_SPEED);
	if (game->key_s)
		move_player(game, -game->player.dir_x * MOVE_SPEED, -game->player.dir_y
			* MOVE_SPEED);
	if (game->key_a)
		move_player(game, -game->player.plane_x * MOVE_SPEED,
			-game->player.plane_y * MOVE_SPEED);
	if (game->key_d)
		move_player(game, game->player.plane_x * MOVE_SPEED,
			game->player.plane_y * MOVE_SPEED);
	return (game->key_w || game->key_s || game->key_a || game->key_d);
}

/*
	Hook: game loop
		It runs on every frame: Applies movement if the key is active
*/

int	game_loop(t_game *game)
{
	int	moved;

	moved = process_movement(game);
	if (game->key_right)
	{
		rotate_player(game, -ROT_SPEED);
		moved = 1;
	}
	if (game->key_left)
	{
		rotate_player(game, ROT_SPEED);
		moved = 1;
	}
	if (moved)
		render_frame(game);
	return (0);
}
