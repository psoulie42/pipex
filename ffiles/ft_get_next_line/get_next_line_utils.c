/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:58:26 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/25 11:30:42 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../pipex.h"

char	*ft_substr(const char *s, unsigned int start, size_t l)
{
	char	*n;
	size_t	i;

	i = 0;
	if (ft_strlen((char *)s) < l)
		l = ft_strlen((char *)s);
	n = malloc((l + 1) * sizeof(char));
	if (!n)
		return (NULL);
	while (ft_strlen((char *)s) > start && s[start + i] && i < l)
	{
		n[i] = s[start + i];
		i++;
	}
	n[i] = 0;
	return (n);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	cc;

	cc = c;
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
