/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:35:54 by psoulie           #+#    #+#             */
/*   Updated: 2024/12/03 11:10:13 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	toggle_quote(int *in_quote)
{
	*in_quote = !(*in_quote);
}

int	quote(char c, int *in_quote)
{
	if (c == '\"' || c == '\'')
	{
		toggle_quote(in_quote);
		return (1);
	}
	return (0);
}

static int	count(char *str, char c)
{
	int	i;
	int	count;
	int	in_quote;

	in_quote = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			quote(str[i], &in_quote);
			count++;
			i++;
			while (str[i] && (str[i] != c || in_quote))
			{
				quote(str[i], &in_quote);
				i++;
			}
		}
		while (str[i] == c && !in_quote)
			i++;
	}
	return (count);
}

static char	*word(char *str, int start, char c)
{
	int		i;
	int		len;
	char	*word;
	int		in_quote;

	in_quote = 0;
	i = 0;
	len = ft_splitonsteroids(str, start, c);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (quote(str[start + i], &in_quote))
			start++;
		word[i] = str[start + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char c)
{
	size_t	i;
	size_t	nbstr;
	char	**spliff;
	int		in_quote;

	spliff = malloc((count((char *)str, c) + 1) * sizeof(char *));
	if (!spliff)
		return (NULL);
	in_quote = 0;
	i = 0;
	nbstr = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			quote(str[i], &in_quote);
			spliff[nbstr++] = word(str, i, c);
			i++;
			while (str[i] && (str[i] != c || in_quote))
				quote(str[i++], &in_quote);
		}
		while (str[i] == c && !in_quote)
			i++;
	}
	return (spliff[nbstr] = NULL, spliff);
}

/* int	main()
{
	char str[] = "genre'laa ca ' passe' yo'";
	int i = 0;
	char c = ' ';
	char **spliff = ft_split(str, c);
	while (i < count(str, c))
	{
		printf("%s\n", spliff[i]);
		i++;
	}
} */
