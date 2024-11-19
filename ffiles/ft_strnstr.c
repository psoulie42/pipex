/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:05:57 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/19 11:37:06 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t n)
{
	size_t	i;
	size_t	j;

	if (ndl[0] == 0)
		return ((char *)hst);
	i = 0;
	while (hst[i] && i < n)
	{
		j = 0;
		if (hst[i] == ndl[j])
		{
			while (hst[i + j] && ndl[j] && hst[i + j] == ndl[j] && i + j < n)
			{
				j++;
			}
			if (!ndl[j])
				return ((char *)&hst[i]);
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
	char ndl[] = "ow";
	char hst[] = "powerbomb";
	printf("%s\n", ft_strnstr(hst, ndl, 15));
} */