/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:46 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/22 14:57:07 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


int main (int argc, char *argv[])
{
    if (argc !=2)
        printf("Error arguments\n");
    else
    {
        if (check_map(argv[1]))
        {
            if (parse_game(argv[1])) // change name
            {
            //     init_game();
            //     render();
            //     mlx_loop();
            //     free(struct);
            //     return (0);
                printf ("Is ok\n");
            }
            //  else
            //  {
            //     // free(struct);
            //     return (-1);
            //  }
        }
        else
            return (printf("Exit\n"),-1);
    }
    return (0);
}
