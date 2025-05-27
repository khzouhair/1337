/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:55:58 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/28 15:48:53 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_test_overflow(int c, char *v[])
{
	int		i;
	int		number;
	int		j;
	char	**s;

	if (v == NULL || *v == NULL)
		return (0);
	i = 1;
	number = 0;
	while (i < c)
	{
		s = ft_split(v[i], ' ');
		j = 0;
		while (s[j])
		{
			if (ft_atoi(s[j], &number) == 'F')
				return (free_split2(s), 0);
			j++;
		}
		i++;
		free_split2(s);
	}
	return (1);
}

int	ft_verify_order(t_stack *pile)
{
	t_stack	*p;

	p = pile;
	while (p->next != NULL)
	{
		if (p->number > p->next->number)
			return (0);
		p = p->next;
	}
	return (1);
}

static void	free_stack(t_stack **pile)
{
	t_stack	*p;

	if (pile == NULL || *pile == NULL)
		return ;
	p = *pile;
	while (*pile != NULL)
	{
		p = *pile;
		(*pile) = (*pile)->next;
		free(p);
		p = NULL;
	}
}

int	main(int c, char *v[])
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (c >= 2)
	{
		ft_create_pile_a(c, v, &pile_a);
		create_index(&pile_a);
		if (ft_test_alldigit(c, v) == 0 || ft_test_overflow(c, v) == 0
			|| ft_check_dup(pile_a) == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (ft_verify_order(pile_a) == 0)
			sort_stack(&pile_a, &pile_b);
		free_stack(&pile_a);
	}
}
