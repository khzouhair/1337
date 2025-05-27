/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:57:32 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/28 15:45:43 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split2(char **s)
{
	int	i;

	i = 0;
	if (s == NULL && *s == NULL)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	if (s)
		free(s);
}

static int	ft_all_digit(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_test_alldigit(int c, char *v[])
{
	int		i;
	int		j;
	char	**s;

	if (v == NULL || *v == NULL)
		return (0);
	i = 1;
	while (i < c)
	{
		s = ft_split(v[i], ' ');
		if (*s == NULL)
			return (free_split2(s), 0);
		j = 0;
		while (s[j])
		{
			if (ft_all_digit(s[j]) == 0)
				return (free_split2(s), 0);
			j++;
		}
		i++;
		free_split2(s);
	}
	return (1);
}

int	ft_check_dup(t_stack *pile)
{
	int		temp;
	t_stack	*p;

	if (pile == NULL)
		return (1);
	p = pile;
	while (pile != NULL)
	{
		temp = pile->number;
		p = pile->next;
		while (p != NULL)
		{
			if (p->number == temp)
				return (1);
			p = p->next;
		}
		pile = pile->next;
	}
	return (0);
}

void	ft_create_pile_a(int c, char *v[], t_stack **pile_a)
{
	int		i;
	int		number;
	char	**s;
	int		j;
	t_stack	*elem;

	if (pile_a == NULL || v == NULL || *v == NULL)
		return ;
	(1) && (i = 1, number = 0);
	while (i < c)
	{
		s = ft_split(v[i], ' ');
		j = 0;
		while (s[j])
		{
			ft_atoi(s[j], &number);
			elem = create_elem(number);
			if (elem == NULL)
				return ;
			ft_add_end(pile_a, elem);
			j++;
		}
		i++;
		free_split2(s);
	}
}
