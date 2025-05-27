/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:29:55 by khzouhai          #+#    #+#             */
/*   Updated: 2025/03/15 10:46:32 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_test(int sign, long r)
{
	if (sign == 1 && r > INT_MAX)
		return (-1);
	else if (sign == -1 && (-r) < INT_MIN)
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

void	exit_error(void)
{
	write(2, "Overflow\n", 9);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	r;

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
			exit_error();
		i++;
	}
	return (sign * (int)r);
}

void	ft_putnbr(long nb)
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
