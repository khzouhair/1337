/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:09:28 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/19 12:44:11 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	copy = (char *)malloc(n + 1);
	if (!copy)
		return (NULL);
	while (i < n)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = (char *)malloc(j + i + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *(s1++);
	while (*s2)
		s3[i++] = *(s2++);
	s3[i] = '\0';
	return (s3);
}

char	*ft_new_content(char *content, size_t *i)
{
	if (!content)
		return (NULL);
	while (*content)
	{
		if (*content == '\n')
			break ;
		(*i)++;
		(content)++;
	}
	if (*content != '\0')
		content++;
	return (content);
}

char	*ft_contentwith_nl(char *content, size_t i)
{
	size_t	j;
	char	*str;

	if (!content || i >= ft_strlen(content))
		return (NULL);
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = content[j];
		j++;
	}
	str[j] = '\n';
	str[j + 1] = '\0';
	return (str);
}
