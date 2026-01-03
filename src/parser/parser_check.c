/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:42:13 by gafreire          #+#    #+#             */
/*   Updated: 2026/01/02 14:34:49 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
    Auxiliary function:
     check if the characters is allowed
*/
static int is_valid_char(char c)
{
    if (c == '0' || c == '1' || c == ' ')
        return (1);
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}

/*
    Auxiliary function:
    check if the character is a player
*/
static int  is_player(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}
/*
    Main function:
     iterate rows, and for each row, iterate columns (letters):
        1. check valid characters
        2. check player
            - save the postion to use later
    3. final check
*/
int validate_map_content(t_game *game)
{
    int x;
    int y;
    int players_count;

    players_count = 0;
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (!is_valid_char(game->map[y][x]))
                return (printf("Error: Invalid character '%c' in map\n",game->map[y][x]), 0);
            if (is_player(game->map[y][x]))
            {
                players_count++;
                game->player_x = x;
                game->player_y = y;
                game->player_dir = game->map[y][x];
                // optional: Change player to floor '0' now that position is saved
                // game->map[y][x] = '0'; 
            }
            x++;
        }
        y++; 
    }
    if (players_count == 0)
        return (printf("Error: Player is missing (N,S,E,W)\n"),0);
    if (players_count > 1)
        return (printf("Error: Too many players. There can only be one.\n"),0);
    return (1);
}
