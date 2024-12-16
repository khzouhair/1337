/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:05:48 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/10 15:40:46 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	lenn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(int a, char *v[])
{
	int	i;

	i = 1;
	if (a > 0)
	{
		while (i < a)
		{
			write(1, v[i], lenn(v[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
