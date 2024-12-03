/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitonsteroids.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:58:42 by psoulie           #+#    #+#             */
/*   Updated: 2024/12/03 11:09:02 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_splitonsteroids(char *str, int start, char c)
{
	int	len;
	int	i;
	int	in_quote;

	len = 0;
	i = 0;
	in_quote = 0;
	while (str[start + len + i] && (str[start + len + i] != c || in_quote))
	{
		if (quote(str[start + len + i], &in_quote))
		{
			len--;
			i++;
		}
		len ++;
	}
	return (len);
}
