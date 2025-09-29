/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:49:04 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 17:49:31 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*prev_last;

	if (!a || a->size < 2)
		return ;
	last = a->top;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->prev = NULL;
	last->next = a->top;
	a->top->prev = last;
	a->top = last;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*prev_last;

	if (!b || b->size < 2)
		return ;
	last = b->top;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->prev = NULL;
	last->next = b->top;
	b->top->prev = last;
	b->top = last;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
