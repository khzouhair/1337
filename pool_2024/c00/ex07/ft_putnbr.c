/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:22:06 by khzouhai          #+#    #+#             */
/*   Updated: 2024/06/27 08:27:58 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	n;

	if (nb >= 0 && nb <= 9)
	{
		n = '0' + nb;
		write(1, &n, 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-1 * nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
