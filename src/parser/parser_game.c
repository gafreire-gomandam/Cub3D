/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:47:27 by gafreire          #+#    #+#             */
/*   Updated: 2025/12/30 16:47:47 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int is_empty_line(char *line)
{
      int i;

      i = 0;
      if (!line)
            return (1);
      while (line[i])
      {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
                  return (0);
            i++;
      }
      return (1);     
}

int parse_game(char *map, t_game *game)
{
      int fd;
      char *line;
      t_list *new_node;

      game->map_list = NULL; // i initialize the list to null to avoid trash
      fd = open(map,O_RDONLY);
      if (fd < 0)
            return (printf("Error: Could not open map file\n"), 0); // change function
      while (1)
      {
            line = get_next_line(fd);
            if (!line)
                  break;
            if (is_empty_line(line))
                  free(line);
            else
            {
                  new_node = ft_lstnew(line);
                  if (!new_node)
                  {
                        free(line);
                        close(fd);
                        return (printf("Error: Malloc failed"),0); // change function
                  }

                  ft_lstadd_back(&game->map_list,new_node);
            }
      }
      
      //     init_game();
      //     render();
      //     mlx_loop();
      //     free(struct);
      close(fd);
      printf("--- READING COMPLETED ---\n");
      t_list *temp = game->map_list;
      while (temp)
      {
          printf("Guardado: %s", (char *)temp->content);
          temp = temp->next;
      }
      return (1);
}
