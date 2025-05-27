/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:56:24 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/26 12:04:38 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_test(int sign, long long int r)
{
	if (sign == 1 && r > 2147483647)
		return ('F');
	else if (sign == -1 && (-1) * r < -2147483648)
		return ('F');
	return ('T');
}

static int	ft_checkwhitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

char	ft_atoi(const char *str, int *number)
{
	int				i;
	int				sign;
	long long int	r;

	r = 0;
	sign = 1;
	i = ft_checkwhitespace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			sign = 1;
		else if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + str[i] - '0';
		if (ft_test(sign, r) != 'T')
			return (ft_test(sign, r));
		i++;
	}
	*number = sign * (int)r;
	return ('T');
}
