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

void	sb(t_data *data)
{
	t_stack	*first;
	t_stack	*second;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	second = data->stack_b->next;
	first->next = second->next;
	second->next = first;
	data->stack_b = second;
	write(1, "sb\n", 3);
}

void	pb(t_data *data)
{
	t_stack	*temp;

	if (!data->stack_a)
		return ;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	temp->next = data->stack_b;
	data->stack_b = temp;
	write(1, "pb\n", 3);
}

void	rb(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	data->stack_b = data->stack_b->next;
	last = data->stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_data *data)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	last = data->stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = data->stack_b;
	data->stack_b = last;
	write(1, "rrb\n", 4);
}
