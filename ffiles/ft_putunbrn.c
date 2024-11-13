/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:25:33 by psoulie           #+#    #+#             */
/*   Updated: 2024/10/18 12:36:11 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count(long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	specialcase(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		write(1, "-2147483648", 11);
		return (11);
	}
}

int	ft_putunbrn(unsigned int n)
{
	int	minus;

	minus = 0;
	if (n == 0)
		return (specialcase(n));
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		minus = 1;
	}
	if (n > 9)
	{
		ft_putunbrn(n / 10);
		ft_putunbrn(n % 10);
	}
	else
		ft_putcharn(n + 48);
	return (minus + count(n));
}
