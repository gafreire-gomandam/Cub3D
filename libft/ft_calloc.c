/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:34:36 by gafreire          #+#    #+#             */
/*   Updated: 2024/10/13 17:21:49 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	size_total;

	size_total = nmemb * size;
	mem = malloc(size_total);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size_total);
	return (mem);
}
