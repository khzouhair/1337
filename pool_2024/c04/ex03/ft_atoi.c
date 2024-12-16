/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:16:41 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/06 09:53:17 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int a, int p)
{
	int	n;

	n = 1;
	while (p > 0)
	{
		n *= a;
		p--;
	}
	return (n);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	r;

	r = 0;
	sign = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (ft_pow(-1, sign) * r);
}
