/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:31:21 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/18 16:40:56 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_stack	*first;
	t_stack	*second;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a;
	second = data->stack_a->next;
	first->next = second->next;
	second->next = first;
	data->stack_a = second;
	write(1, "sa\n", 3);
}

void	pa(t_data *data)
{
	t_stack	*temp;

	if (!data->stack_b)
		return ;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	temp->next = data->stack_a;
	data->stack_a = temp;
	write(1, "pa\n", 3);
}

void	ra(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a;
	data->stack_a = data->stack_a->next;
	last = data->stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_data *data)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	last = data->stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = data->stack_a;
	data->stack_a = last;
	write(1, "rra\n", 4);
}
