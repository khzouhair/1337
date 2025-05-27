/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:57:10 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/26 12:05:54 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_stack **pile, char c)
{
	if ((*pile)->number > (*pile)->next->number)
		ft_sa_sb(pile, c);
}

static void	ft_sort_three(t_stack **pile)
{
	if ((*pile)->number > (*pile)->next->number
		&& (*pile)->number > (*pile)->next->next->number)
	{
		ft_ra_rb(pile, 'a');
		if ((*pile)->number > ((*pile)->next)->number)
			ft_sa_sb(pile, 'a');
	}
	else if ((((*pile)->next)->next)->number > (*pile)->number
		&& ((*pile)->next)->number < (((*pile)->next)->next)->number)
	{
		if ((*pile)->number > ((*pile)->next)->number)
			ft_sa_sb(pile, 'a');
	}
	else if ((*pile)->number < ((*pile)->next)->number
		&& ((*pile)->next)->number > (((*pile)->next)->next)->number)
	{
		ft_rra_rrb(pile, 'a');
		if ((*pile)->number > ((*pile)->next)->number)
			ft_sa_sb(pile, 'a');
	}
}

static void	ft_sort_four(t_stack **pile_a)
{
	t_stack	*pile_b;

	pile_b = NULL;
	while ((*pile_a)->index != 0)
		ft_ra_rb(pile_a, 'a');
	ft_pa_pb(&pile_b, pile_a, 'b');
	ft_sort_three(pile_a);
	ft_pa_pb(pile_a, &pile_b, 'a');
}

static void	ft_sort_five(t_stack **pile_a)
{
	t_stack	*pile_b;

	pile_b = NULL;
	while (ft_stacklen(*pile_a) > 3)
	{
		if ((*pile_a)->index < 2)
			ft_pa_pb(&pile_b, pile_a, 'b');
		else
			ft_ra_rb(pile_a, 'a');
	}
	ft_sort_three(pile_a);
	if (ft_verify_order(pile_b))
		ft_sa_sb(&pile_b, 'b');
	ft_pa_pb(pile_a, &pile_b, 'a');
	ft_pa_pb(pile_a, &pile_b, 'a');
}

void	sort_stack(t_stack **pile_a, t_stack **pile_b)
{
	if (pile_a == NULL || *pile_a == NULL)
		return ;
	if (ft_stacklen(*pile_a) == 2)
		ft_sort_two(pile_a, 'a');
	else if (ft_stacklen(*pile_a) == 3)
		ft_sort_three(pile_a);
	else if (ft_stacklen(*pile_a) == 4)
		ft_sort_four(pile_a);
	else if (ft_stacklen(*pile_a) == 5)
		ft_sort_five(pile_a);
	else
		push_swap(pile_a, pile_b);
}
