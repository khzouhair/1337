/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:33:19 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/10 15:41:10 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int a, char *v[])
{
	int	i;
	int	j;

	i = a - 1;
	while (i > 0)
	{
		j = 0;
		while (v[i][j])
		{
			write(1, &v[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
