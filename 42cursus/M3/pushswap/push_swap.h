/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:57:56 by khzouhai          #+#    #+#             */
/*   Updated: 2025/02/28 14:14:45 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;

}					t_stack;

char				**ft_split(char const *str, char charset);
char				ft_atoi(const char *str, int *number);
int					ft_stacklen(t_stack *pile);
t_stack				*create_elem(int number);
void				ft_push(t_stack **pile, t_stack *elem);
int					ft_test_alldigit(int c, char *v[]);
int					ft_check_dup(t_stack *pile);
void				push_to_b(t_stack **pile_a, t_stack **pile_b, int range);
int					ft_max(t_stack *pile, int i);
void				push_to_a(t_stack **pile_a, t_stack **pile_b);
void				ft_sa_sb(t_stack **pile, char c);
void				ft_pa_pb(t_stack **pile_a, t_stack **pile_b, char c);
void				ft_ra_rb(t_stack **pile, char c);
void				ft_freelast(t_stack **pile);
void				ft_rra_rrb(t_stack **pile, char c);
void				sort_stack(t_stack **pile_a, t_stack **pile_b);
void				push_swap(t_stack **pile_a, t_stack **pile_b);
void				ft_create_pile_a(int c, char *v[], t_stack **pile_a);
void				ft_add_end(t_stack **pile, t_stack *elem);
void				create_index(t_stack **pile);
void				free_split2(char **s);
int					ft_verify_order(t_stack *pile);

#endif
