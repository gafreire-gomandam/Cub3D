/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:54:57 by gafreire          #+#    #+#             */
/*   Updated: 2025/11/11 20:00:12 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	if (!*lst)
		return ;
	head = *lst;
	while (head)
	{
		node = head->next;
		del(head->content);
		free(head);
		head = node;
	}
	*lst = NULL;
}
