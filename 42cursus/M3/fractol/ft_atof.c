/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:15:01 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/24 13:36:09 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_func(int i, const char *str)
{
	double	r;
	int		j;

	(1) && (r = 0, j = 0);
	if (str[i] == '.')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + str[i] - '0';
		j++;
		i++;
	}
	while (j > 0)
	{
		r = r * 0.1;
		j--;
	}
	return (r);
}

static int	ft_checkwhitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

double	ft_atof(const char *str)
{
	int		i;
	double	sign;
	double	r;

	(1) && (r = 0, sign = 1, i = ft_checkwhitespace(str));
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
		i++;
	}
	r = r + ft_func(i, str);
	return (sign * r);
}
