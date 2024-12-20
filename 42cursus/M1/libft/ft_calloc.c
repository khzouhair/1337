/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:10:39 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/05 18:39:21 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	taille;
	void	*p;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	taille = count * size;
	p = malloc(taille);
	if (!p)
		return (NULL);
	while (i < taille)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}
