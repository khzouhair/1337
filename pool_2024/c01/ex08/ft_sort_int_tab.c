/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:15:04 by khzouhai          #+#    #+#             */
/*   Updated: 2024/06/28 09:25:19 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	k;

	i = 0;
	while (i < size)
	{
		temp = tab[i];
		k = i + 1;
		while (k < size)
		{
			if (temp > tab[k])
			{
				temp = tab[k];
				tab[k] = tab[i];
				tab[i] = temp;
			}
			k++;
		}
		i++;
	}
}
