/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:35 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/27 17:06:18 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		i++;
	}
	else if (n > 9)
	{
		i += ft_putunsigned(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	return (i);
}
