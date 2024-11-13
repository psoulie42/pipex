/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:18:13 by psoulie           #+#    #+#             */
/*   Updated: 2024/10/18 14:20:28 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_railswitch(va_list arg, char a)
{
	int	len;

	len = 0;
	if (a == 'c')
		len += ft_putcharn(va_arg(arg, int));
	if (a == 's')
		len += ft_putstrn(va_arg(arg, char *));
	if (a == 'p')
		len += ft_putptrn(va_arg(arg, void *));
	if (a == 'd' || a == 'i')
		len += ft_putnbrn(va_arg(arg, int));
	if (a == 'u')
		len += ft_putunbrn(va_arg(arg, int));
	if (a == 'x')
		len += ft_putnbrhexn(va_arg(arg, unsigned int), 'x');
	if (a == 'X')
		len += ft_putnbrhexn(va_arg(arg, unsigned int), 'X');
	if (a == '%')
		len += ft_putcharn('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_railswitch(args, str[++i]);
		}
		else
			len += ft_putcharn(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
