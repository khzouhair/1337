/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:28:12 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/09 09:36:33 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_iseq(const char s1, const char s2, int *temp)
{
	if (s1 != s2)
		*temp = 1;
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		temp;
	size_t	n;

	n = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (*str != '\0' && n < len)
	{
		if (*str == *to_find)
		{
			i = 0;
			temp = 0;
			while (str[i] && to_find[i] != '\0' && i + n < len)
			{
				ft_iseq(to_find[i], str[i], &temp);
				i++;
			}
			if (temp == 0 && to_find[i] == '\0')
				return ((char *)str);
		}
		n++;
		str++;
	}
	return (NULL);
}
