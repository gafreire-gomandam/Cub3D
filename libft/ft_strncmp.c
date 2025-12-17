/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:53:20 by gafreire          #+#    #+#             */
/*   Updated: 2024/10/20 15:06:29 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	char_s1;
	unsigned char	char_s2;

	i = 0;
	while (i < n)
	{
		char_s1 = (unsigned char)s1[i];
		char_s2 = (unsigned char)s2[i];
		if ((char_s1 == '\0' || char_s2 == '\0') || (char_s1 != char_s2))
			return (char_s1 - char_s2);
		i++;
	}
	return (0);
}
