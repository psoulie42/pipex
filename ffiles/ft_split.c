/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:35:54 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/19 13:57:25 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		while (str[i] == c && str[i])
			i++;
	}
	return (count);
}

static char	*ftdup(char *str, int start, char c)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (str[start + len] != c && str[start + len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	**ft_split(const char *str, char c)
{
	size_t	i;
	size_t	nbstr;
	char	**spliff;

	spliff = malloc((count((char *)str, c) + 1) * sizeof(char *));
	if (!spliff)
		return (NULL);
	i = 0;
	nbstr = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			spliff[nbstr] = ftdup((char *)str, i, c);
			nbstr++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (spliff[nbstr] = NULL, spliff);
}

/* int	main()
{
	char str[] = "genre la ca passe   vrm? ?";
	int i = 0;
	char c = ' ';
	while (i < count(str, c))
	{
		printf("%s\n", ft_split(str, c)[i]);
		free(ft_split(str, c)[i]);
		i++;
	}
	free(ft_split(str, c));
} */