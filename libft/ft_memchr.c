/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:47:37 by gafreire          #+#    #+#             */
/*   Updated: 2024/10/20 12:52:33 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*char_str;
	size_t				i;

	char_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (char_str[i] == (unsigned char)c)
			return ((void *)&char_str[i]);
		i++;
	}
	return (NULL);
}
