/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:45:17 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 21:42:03 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	a->top->prev = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	b->top->prev = NULL;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
