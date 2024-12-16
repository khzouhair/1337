/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:55:36 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/14 16:47:58 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	error_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 32 || (base[i] >= 9
				&& base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	len;
    int sign;
    sign = 1;

	nb = 0;
	len = ft_strlen(str);
	i = 0;
	if (error_base(base))
	{
        while (str[i]==32 || (str[i]>=9 && str[i]<=13))
            i++;
        while (str[i]=='-' || str[i]=='+')
        {
                if (str[i]=='-')
                {
                    sign = -1;
                    len--;
                }
                   
                i++;
        }
        
		while (str[i])
		{
			nb += ft_recursive_power(ft_strlen(base), len-1) * ft_index(str[i], base);
			len--;
			i++;
		}
	}
	return (nb*sign);
}
int main()
{
    printf("%d", ft_atoi_base("-11100000010001    ","01"));
}