/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:35:59 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/15 14:03:54 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen1(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	ft_strlen(char **str, int size, char *sep)
{
	int	i;
	int	j;
	int	sum;

	sum = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			j++;
		}
		sum += j;
		i++;
	}
	return (sum + ft_strlen1(sep) * (size - 1));
}

void	ft_strini(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		k;
	int		j;
	int		i;
	char	*str;

	ft_strini(&i, &j);
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	str = (char *)malloc(sizeof(char) * (ft_strlen(strs, size, sep) + 1));
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
		{
			str[j++] = strs[i][k++];
		}
		k = 0;
		while (sep[k] && i != (size - 1))
		{
			str[j++] = sep[k++];
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
