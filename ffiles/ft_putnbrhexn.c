/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:26:12 by psoulie           #+#    #+#             */
/*   Updated: 2024/10/18 15:04:07 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count(unsigned long nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static int	specialcase(void)
{
	write(1, "0", 1);
	return (1);
}

int	ft_putnbrhexn(unsigned long nb, char a)
{
	char	*base;
	int		minus;

	minus = 0;
	if (a == 'x')
		base = "0123456789abcdef";
	if (a == 'X')
		base = "0123456789ABCDEF";
	if (nb == 0)
		return (specialcase());
	if (nb > 15)
	{
		ft_putnbrhexn(nb / 16, a);
		ft_putnbrhexn(nb % 16, a);
	}
	else
	{
		write(1, &base[nb], 1);
	}
	return (minus + count(nb));
}
