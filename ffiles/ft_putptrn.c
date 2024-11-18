/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:52:17 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/18 13:51:54 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_putptrn(void *ptr)
{
	int				len;
	unsigned long	val;

	val = (unsigned long)ptr;
	len = 0;
	len += ft_putstrn("0x");
	len += ft_putnbrhexn(val, 'x');
	return (len);
}
