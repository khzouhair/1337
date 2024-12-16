/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:00:47 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/10 21:43:13 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcomp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int a, char *v[])
{
	int	i;

	i = 1;
	while (i < a)
	{
		write(1, v[i], ft_strlen(v[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	str_swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

int	main(int a, char *v[])
{
	int	i;
	int	j;
	int	min;

	i = 1;
	while (i < (a - 1))
	{
		min = i;
		j = i + 1;
		while (j < a)
		{
			if (ft_strcomp(v[min], v[j]) > 0)
				min = j;
			j++;
		}
		if (min != i)
		{
			str_swap(&v[min], &v[i]);
		}
		i++;
	}
	ft_putstr(a, v);
	return (0);
}
