/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:46 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/30 13:38:25 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


int main (int argc, char *argv[])
{
    t_game game;
    if (argc !=2)
        printf("Error arguments\n");
    else
    {
        if (check_map(argv[1]))
        {
            // create struct
            if (parse_game(argv[1],&game)) 
            {
                return (0);
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
