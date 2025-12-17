/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:18:14 by gafreire          #+#    #+#             */
/*   Updated: 2024/10/17 16:58:44 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*mem;

	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if ((size - start) < len)
		len = size - start;
	mem = (char *)malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
