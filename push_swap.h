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

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
}	t_data;

/* main.c */
int		main(int argc, char **argv);

/* parser.c */
int		parse_args(t_data *data, int argc, char **argv);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
long	ft_atol(char *str);

/* stack_utils.c */
t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);

/* operations_a.c */
void	sa(t_data *data);
void	pa(t_data *data);
void	ra(t_data *data);
void	rra(t_data *data);

/* operations_b.c */
void	sb(t_data *data);
void	pb(t_data *data);
void	rb(t_data *data);
void	rrb(t_data *data);

/* operations_both.c */
void	ss(t_data *data);
void	rr(t_data *data);
void	rrr(t_data *data);

/* indexing.c */
void	index_stack(t_stack *stack);
int		get_min_value(t_stack *stack);

/* sort_small.c */
void	sort_three(t_data *data);
void	sort_small(t_data *data);

/* radix_sort.c */
void	radix_sort(t_data *data);
int		get_max_bits(int size);

/* utils.c */
void	ft_putstr_fd(char *str, int fd);
void	error_exit(t_data *data);
int		ft_strlen(char *str);

#endif
