/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-23 15:14:16 by gafreire          #+#    #+#             */
/*   Updated: 2024-10-23 15:14:16 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_sub(char **sub, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(sub[i]);
		i++;
	}
	free(sub);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static int	size_sub(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**place_sub(char const *s, char c, char **sub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count = size_sub(&s[i], c);
			sub[j] = (char *)malloc((count + 1) * sizeof(char));
			if (!sub[j])
				return (free_sub(sub, j), NULL);
			count = 0;
			while (s[i] && s[i] != c)
				sub[j][count++] = s[i++];
			sub[j++][count] = '\0';
		}
	}
	return (sub[j] = NULL, sub);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**sub;

	if (!s)
		return (NULL);
	word = count_words(s, c);
	sub = (char **)malloc((word + 1) * sizeof(char *));
	if (!sub)
		return (NULL);
	return (place_sub(s, c, sub));
}
