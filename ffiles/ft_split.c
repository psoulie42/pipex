/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:35:54 by psoulie           #+#    #+#             */
/*   Updated: 2024/12/02 19:57:36 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	toggle_quote(int *in_quote)
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
				if (in_quote && quote(str[i++], &in_quote))
					break ;
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
	len = 0;
	while (str[start + len] && (str[start + len] != c || in_quote))
	{
		quote(str[start + len], &in_quote);
		len ++;
	}
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		if (quote(word[i++], &in_quote) && !in_quote)
			break ;
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
			spliff[nbstr] = word(str, i, c);
			nbstr++;
			i++;
			while (str[i] && (str[i] != c || in_quote))
			{
				quote(str[i], &in_quote);
				i++;
				if (in_quote && quote(str[i++], &in_quote))
					break ;
			}
		}
		while (str[i] == c && !in_quote)
			i++;
	}
	return (spliff[nbstr] = NULL, spliff);
}

/* int	main()
{
	char str[] = "genre 'laa hre'a";
	int i = 0;
	char c = ' ';
	char **spliff = ft_split(str, c);
	while (i < count(str, c))
	{
		printf("%s\n", spliff[i]);
		i++;
	}
} */
