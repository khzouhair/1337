/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:55:14 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/08 11:59:36 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	error_base(char *base)
{
	int	i;
	int	k;

	i = 0;
	if (base[i] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == 32 || base[i] == 43 || base[i] == 45)
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		k = i + 1;
		while (base[k])
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (error_base(base))
	{
		if (nbr >= 0 && nbr <= 2147483647)
		{
			if (nbr / base_len != 0)
				ft_putnbr_base(nbr / base_len, base);
			write(1, &base[nbr % base_len], 1);
		}
		else if (nbr == -2147483648)
		{
			if (nbr / base_len != 0)
				ft_putnbr_base(nbr / base_len, base);
			write(1, &base[-(nbr % base_len)], 1);
		}
		else
		{
			write(1, "-", 1);
			ft_putnbr_base(-nbr, base);
		}
	}
}
int main()
{
    ft_putnbr_base(16,"0123456789abcdef");
}