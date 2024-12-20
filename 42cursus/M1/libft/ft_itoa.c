/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:05:28 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/04 16:32:37 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigit(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = (-1) * n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*int_to_str(int n, char *str, size_t *i)
{
	if (n == -2147483648)
	{
		return (ft_strcpy(str, "-2147483648"));
	}
	if (n >= 0 && n <= 9)
	{
		str[*i] = n + '0';
		(*i)++;
	}
	else if (n > 9 && n <= 2147483647)
	{
		int_to_str(n / 10, str, i);
		int_to_str(n % 10, str, i);
	}
	else if (n < 0)
	{
		str[*i] = '-';
		(*i)++;
		int_to_str(-n, str, i);
	}
	str[*i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	if (n == 0)
		i = 1;
	else
		i = countdigit(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	return (int_to_str(n, str, &j));
}
