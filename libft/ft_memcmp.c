/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 03:33:02 by gafreire          #+#    #+#             */
/*   Updated: 2024/10/20 13:02:42 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	i = 0;
	char_str1 = (unsigned char *)s1;
	char_str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (char_str1[i] != char_str2[i])
		{
			return (char_str1[i] - char_str2[i]);
		}
		i++;
	}
	return (0);
}
