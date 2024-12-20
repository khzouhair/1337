/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:12:51 by khzouhai          #+#    #+#             */
/*   Updated: 2024/11/09 08:50:52 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!lst || !del)
		return ;
	if (!(*lst))
		return ;
	p = *lst;
	while (p != NULL)
	{
		*lst = p->next;
		del((p)->content);
		free(p);
		p = *lst;
	}
}
