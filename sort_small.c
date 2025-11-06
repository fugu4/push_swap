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

static int	find_max_index(t_stack *stack)
{
	int	max_index;
	int	max_value;

	if (!stack)
		return (0);
	max_index = 0;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_index = stack->index;
		}
		stack = stack->next;
	}
	return (max_index);
}

void	sort_three(t_data *data)
{
	int	max;

	if (is_sorted(data->stack_a))
		return ;
	max = find_max_index(data->stack_a);
	if (data->stack_a->index == max)
		ra(data);
	else if (data->stack_a->next->index == max)
		rra(data);
	if (data->stack_a->index > data->stack_a->next->index)
		sa(data);
}

static void	sort_four(t_data *data)
{
	while (data->stack_a->index != 0)
		ra(data);
	pb(data);
	sort_three(data);
	pa(data);
}

static void	sort_five(t_data *data)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if (data->stack_a->index <= 1)
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
	}
	sort_three(data);
	if (data->stack_b->index < data->stack_b->next->index)
		sb(data);
	pa(data);
	pa(data);
}

void	sort_small(t_data *data)
{
	if (data->size == 2)
	{
		if (data->stack_a->value > data->stack_a->next->value)
			sa(data);
	}
	else if (data->size == 3)
		sort_three(data);
	else if (data->size == 4)
		sort_four(data);
	else if (data->size == 5)
		sort_five(data);
}
