/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:17:25 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/04 16:04:45 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] == charset && str[i])
		i++;
	if (str[i] != '\0')
		count++;
	while (str[i])
	{
		if (str[i] == charset && str[i + 1] != charset && str[i + 1] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char const	*copy(char const *start, char const *end)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(end - start + 1);
	if (!copy)
		return (NULL);
	while (start < end)
	{
		copy[i] = *start;
		start++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	free_split(char **split, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_start_end(char const **str, char charset, char const **start)
{
	while (**str == charset && **str)
		(*str)++;
	*start = *str;
	while (**str != charset && **str)
		(*str)++;
}

char	**ft_split(char const *str, char charset)
{
	char const	*start;
	char		**result;
	int			i;
	int			count;

	i = 0;
	if (!str)
		return (NULL);
	count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (*str && i < count)
	{
		ft_start_end(&str, charset, &start);
		result[i] = (char *)copy(start, str);
		if (!result[i])
		{
			free_split(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
