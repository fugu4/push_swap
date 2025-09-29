/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:32:06 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 18:32:19 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size < 3)
		return ;
	first = a->top->rank;
	second = a->top->next->rank;
	third = a->top->next->next->rank;
	if (first > second && second < third && third > first)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && third < first)
		ra(a);
	else if (first < second && second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && third < first)
		rra(a);
}

static int	find_min_rank(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack->top)
		return (-1);
	current = stack->top;
	min = current->rank;
	while (current)
	{
		if (current->rank < min)
			min = current->rank;
		current = current->next;
	}
	return (min);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min;

	if (a->size == 2)
	{
		if (a->top->rank > a->top->next->rank)
			sa(a);
		return ;
	}
	while (a->size > 3)
	{
		min = find_min_rank(a);
		while (a->top->rank != min)
		{
			if (a->top->next->rank == min)
				sa(a);
			else
				ra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
