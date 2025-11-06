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

void	ss(t_data *data)
{
	t_stack	*temp;

	if (data->stack_a && data->stack_a->next)
	{
		temp = data->stack_a;
		data->stack_a = data->stack_a->next;
		temp->next = data->stack_a->next;
		data->stack_a->next = temp;
	}
	if (data->stack_b && data->stack_b->next)
	{
		temp = data->stack_b;
		data->stack_b = data->stack_b->next;
		temp->next = data->stack_b->next;
		data->stack_b->next = temp;
	}
	write(1, "ss\n", 3);
}

void	rr(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	if (data->stack_a && data->stack_a->next)
	{
		first = data->stack_a;
		data->stack_a = data->stack_a->next;
		last = data->stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	if (data->stack_b && data->stack_b->next)
	{
		first = data->stack_b;
		data->stack_b = data->stack_b->next;
		last = data->stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	write(1, "rr\n", 3);
}

static void	do_rra_internal(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_data *data)
{
	do_rra_internal(&data->stack_a);
	do_rra_internal(&data->stack_b);
	write(1, "rrr\n", 4);
}
