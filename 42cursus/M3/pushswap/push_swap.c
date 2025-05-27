/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:56:57 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/28 14:14:03 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **pile_a, t_stack **pile_b, int range)
{
	int	i;

	i = 0;
	while (*pile_a)
	{
		if ((*pile_a)->index <= i)
		{
			ft_pa_pb(pile_b, pile_a, 'b');
			i++;
		}
		else if ((*pile_a)->index <= (i + range))
		{
			ft_pa_pb(pile_b, pile_a, 'b');
			if (ft_stacklen(*pile_b) > 1)
			{
				ft_ra_rb(pile_b, 'b');
			}
			i++;
		}
		else
		{
			ft_ra_rb(pile_a, 'a');
		}
	}
}

int	ft_max(t_stack *pile, int i)
{
	int	j;

	j = 1;
	while (pile != NULL)
	{
		if (pile->index == i)
		{
			return (j);
		}
		j++;
		pile = pile->next;
	}
	return (0);
}

void	push_to_a(t_stack **pile_a, t_stack **pile_b)
{
	int	len_pile_b;
	int	biggest_index;
	int	position;

	len_pile_b = ft_stacklen(*pile_b);
	while (len_pile_b > 0)
	{
		biggest_index = len_pile_b - 1;
		if ((*pile_b)->index == biggest_index)
			ft_pa_pb(pile_a, pile_b, 'a');
		else
		{
			position = ft_max(*pile_b, biggest_index);
			if (position <= len_pile_b / 2)
				ft_ra_rb(pile_b, 'b');
			else
				ft_rra_rrb(pile_b, 'b');
		}
		len_pile_b = ft_stacklen(*pile_b);
	}
}

void	push_swap(t_stack **pile_a, t_stack **pile_b)
{
	int	len_pile_a;
	int	range;

	len_pile_a = ft_stacklen(*pile_a);
	if (len_pile_a <= 100)
		range = 15;
	else
		range = 32;
	push_to_b(pile_a, pile_b, range);
	push_to_a(pile_a, pile_b);
}
