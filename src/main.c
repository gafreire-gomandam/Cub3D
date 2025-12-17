/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:46 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/17 11:33:44 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"


int check_map(char *map)
{
    int len;

    len = ft_strlen(map); // change function
    if (len > 4)
    {
        if (ft_strncmp(map + (len - 4),".cub",4) != 0 && strncmp(map + (len - 4),".xpm",4) != 0 )//change function
            return (printf("File invalid\n"),-1);
    }
    else
        return (printf("Not valid map\n"),-1);
    return (0);
}

int main (int argc, char *argv[])
{
    if (argc !=2)
        printf("Error arguments\n");
    else
    {
        if (check_map(argv[1]) != -1)
        {
            //  if (parse_cub(argv[1])) // change name
            //  {
            //     init_game();
            //     render();
            //     mlx_loop();
            //     free(struct);
            //     return (0);
            //  }
            //  else
            //  {
            //     // free(struct);
            //     return (-1);
            //  }
            printf ("Is ok\n");
        }
        else
            return (printf("Exit\n"),-1);
    }
    return (0);
}
