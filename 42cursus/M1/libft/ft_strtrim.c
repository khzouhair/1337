/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:30:47 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/09 09:19:59 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(const char str, const char *set)
{
	while (*set)
	{
		if (*set == str)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_initialize(size_t *k, size_t *j, size_t *i)
{
	*k = 0;
	*j = 0;
	*i = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	lens1;
	size_t	i;
	size_t	j;
	size_t	k;

	ft_initialize(&k, &j, &i);
	if (!s1 || !set)
		return (NULL);
	lens1 = ft_strlen(s1);
	while (ft_isin(s1[i], set))
		i++;
	if (i < lens1)
	{
		while (ft_isin(s1[lens1 - 1], set))
			lens1--;
	}
	copy = (char *)malloc(lens1 - i + 1);
	if (!copy)
		return (NULL);
	while (i < lens1)
		copy[k++] = s1[i++];
	copy[k] = '\0';
	return (copy);
}
