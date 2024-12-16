/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:54:19 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/09 09:04:59 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb >= 0)
	{
		if (nb == 0)
		{
			return (1);
		}
		while (nb > 0)
		{
			fact *= nb;
			nb--;
		}
		return (fact);
	}
	return (0);
}
