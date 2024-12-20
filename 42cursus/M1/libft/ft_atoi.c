/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:44 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/09 09:37:00 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test(int sign, unsigned long long int r)
{
	if (sign == 1 && r > LONG_MAX)
		return (-1);
	else if (sign == -1 && r > LONG_MAX)
		return (0);
	return (1);
}

static int	ft_checkwhitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	r;

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
		if (ft_test(sign, r) != 1)
			return (ft_test(sign, r));
		i++;
	}
	return (sign * (int)r);
}
