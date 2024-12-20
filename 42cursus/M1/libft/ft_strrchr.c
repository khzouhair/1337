/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:28:36 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/03 18:10:04 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	lastoccur;
	int	i;
	int	t;

	t = 0;
	i = 0;
	lastoccur = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			lastoccur = i;
			t = 1;
		}
		i++;
	}
	if (t == 1)
		return ((char *)(str + lastoccur));
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (NULL);
}
