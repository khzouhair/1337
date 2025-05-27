/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:57:21 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/26 12:06:06 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(t_stack *pile)
{
	int	i;

	i = 0;
	while (pile != NULL)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

t_stack	*create_elem(int number)
{
	t_stack	*pile;

	pile = (t_stack *)malloc(sizeof(t_stack));
	if (!pile)
		return (NULL);
	pile->number = number;
	pile->index = 0;
	pile->next = NULL;
	return (pile);
}

void	ft_push(t_stack **pile, t_stack *elem)
{
	if (pile == NULL)
		return ;
	if (*pile == NULL)
		*pile = elem;
	else
	{
		elem->next = *pile;
		*pile = elem;
	}
}

void	create_index(t_stack **pile)
{
	t_stack	*p1;
	t_stack	*p2;

	if (pile == NULL || *pile == NULL)
		return ;
	(1) && (p1 = *pile, p2 = *pile);
	while (p1 != NULL)
	{
		while (p2 != NULL)
		{
			if ((p1)->number > p2->number)
				p1->index++;
			p2 = p2->next;
		}
		p2 = *pile;
		p1 = p1->next;
	}
}

void	ft_add_end(t_stack **pile, t_stack *elem)
{
	t_stack	*p;

	p = *pile;
	if (pile == NULL)
		return ;
	if (*pile == NULL)
		*pile = elem;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = elem;
	}
}
