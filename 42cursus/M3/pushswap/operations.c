/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:56:49 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/28 15:20:22 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_stack **pile, char c)
{
	t_stack	*p;
	int		temp;
	int		temp_i;

	if (c == 'a' && (*pile) == NULL)
		return ;
	if (c == 'b' && (*pile) == NULL)
		return ;
	p = *pile;
	p = p->next;
	temp = p->number;
	temp_i = p->index;
	p->number = (*pile)->number;
	p->index = (*pile)->index;
	(*pile)->number = temp;
	(*pile)->index = temp_i;
	if (c == 'b')
		write(1, "sb\n", 3);
	else
		write(1, "sa\n", 3);
}

void	ft_pa_pb(t_stack **pile_a, t_stack **pile_b, char c)
{
	t_stack	*elem_b;
	t_stack	*p;

	if ((pile_b == NULL || *pile_b == NULL))
		return ;
	elem_b = create_elem((*pile_b)->number);
	if (!elem_b)
		return ;
	elem_b->index = (*pile_b)->index;
	ft_push(pile_a, elem_b);
	p = *pile_b;
	*pile_b = (*pile_b)->next;
	free(p);
	p = NULL;
	if (c == 'b')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	ft_ra_rb(t_stack **pile, char c)
{
	t_stack	*p;
	int		temp;
	int		temp_i;

	if (pile == NULL || *pile == NULL)
		return ;
	p = *pile;
	temp = (*pile)->number;
	temp_i = (*pile)->index;
	while (p->next != NULL)
	{
		p->number = (p->next)->number;
		p->index = p->next->index;
		p = p->next;
	}
	p->number = temp;
	p->index = temp_i;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_freelast(t_stack **pile)
{
	t_stack	*p;

	if (pile == NULL || *pile == NULL)
		return ;
	p = *pile;
	while ((p->next)->next != NULL)
		p = p->next;
	free(p->next);
	p->next = NULL;
}

void	ft_rra_rrb(t_stack **pile, char c)
{
	t_stack	*p;
	t_stack	*elem;

	if (pile == NULL || *pile == NULL)
		return ;
	p = *pile;
	while (p->next != NULL)
		p = p->next;
	elem = create_elem(p->number);
	if (!elem)
		return ;
	elem->index = p->index;
	ft_freelast(pile);
	ft_push(pile, elem);
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
