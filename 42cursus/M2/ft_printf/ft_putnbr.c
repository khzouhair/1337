/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:54 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/27 17:05:54 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		i += ft_putstr("-2147483648");
	}
	else if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		i++;
	}
	else if (n <= INT_MAX && n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		i++;
		i += ft_putnbr((-1) * n);
	}
	return (i);
}
