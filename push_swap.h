/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:06:03 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 21:46:26 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

t_stack				*init_stack(void);
void				push_node(t_stack *stack, int value);
int					pop_node(t_stack *stack);
void				free_stack(t_stack *stack);
int					is_sorted(t_stack *stack);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);

void				rrr(t_stack *a, t_stack *b);

int					ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);
void				error_exit(t_stack *a, t_stack *b);
int					check_duplicates(int *arr, int size);
void				ft_putendl_fd(char *s, int fd);

void				rank_elements(t_stack *stack);

void				radix_sort(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				sort_small(t_stack *a, t_stack *b);

#endif
