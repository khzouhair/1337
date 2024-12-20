/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:32:25 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/09 09:24:04 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*news;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
		len = 0;
	if (len > i - start)
		len = i - start;
	i = 0;
	news = (char *)malloc(len + 1);
	if (!news)
		return (NULL);
	while (i < len)
	{
		news[i] = (char)s[start + i];
		i++;
	}
	news[i] = '\0';
	return (news);
}
