/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:16:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/11/10 19:08:16 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*mem;

	size = ft_strlen(s1) + ft_strlen(s2);
	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, s1, ft_strlen(s1) + 1);
	ft_strlcat(mem, s2, size + 1);
	return (mem);
}
