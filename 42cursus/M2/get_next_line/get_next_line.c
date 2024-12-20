/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:08:54 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/27 12:42:11 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **buffer)
{
	if (!buffer || !*buffer)
		return ;
	free(*buffer);
	*buffer = NULL;
}

char	*ft_extractline(char **buffer, char **buffer2)
{
	char	*d;
	size_t	i;
	char	*line;

	line = NULL;
	d = *buffer;
	*buffer = ft_strjoin(*buffer, *buffer2);
	if (d)
		ft_free(&d);
	if (search_new_line(*buffer2))
	{
		i = 0;
		d = *buffer;
		*buffer = ft_strdup(ft_new_content(*buffer, &i));
		line = ft_contentwith_nl(d, i);
		ft_free(&d);
		ft_free(buffer2);
		if (*buffer)
		{
			if (ft_strlen(*buffer) == 0)
				ft_free(buffer);
		}
	}
	return (line);
}

char	*ft_extract_remaining(char **buffer)
{
	size_t	i;
	char	*d;
	char	*line;

	d = NULL;
	while (*buffer != NULL)
	{
		if (search_new_line(*buffer))
		{
			i = 0;
			d = *buffer;
			*buffer = ft_strdup(ft_new_content(*buffer, &i));
			line = ft_contentwith_nl(d, i);
			ft_free(&d);
		}
		else
		{
			line = ft_strdup(*buffer);
			ft_free(buffer);
		}
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buffer2;
	char		*line;
	ssize_t		bytes_read;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX)
		return (ft_free(&buffer), NULL);
	buffer2 = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer2)
		return (ft_free(&buffer), NULL);
	bytes_read = read(fd, buffer2, BUFFER_SIZE);
	while ((bytes_read) > 0)
	{
		buffer2[bytes_read] = '\0';
		line = ft_extractline(&buffer, &buffer2);
		if (line)
			return (line);
		bytes_read = read(fd, buffer2, BUFFER_SIZE);
	}
	ft_free(&buffer2);
	if (buffer != NULL && ft_strlen(buffer) == 0)
		ft_free(&buffer);
	return (ft_extract_remaining(&buffer));
}
