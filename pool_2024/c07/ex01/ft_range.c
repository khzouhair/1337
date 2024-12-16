/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:11:37 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/13 12:42:44 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	p = (int *)malloc(sizeof(int) * (max - min));
	if (!p)
		return (0);
	while (min < max)
	{
		p[i] = min;
		i++;
		min++;
	}
	return (p);
}
