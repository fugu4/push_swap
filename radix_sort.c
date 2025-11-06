/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:31:53 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 18:31:56 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	radix_sort_bit(t_data *data, int bit, int size)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (i < size)
	{
		if (((data->stack_a->index >> bit) & 1) == 0)
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
		i++;
	}
	while (pushed--)
		pa(data);
}

void	radix_sort(t_data *data)
{
	int	max_bits;
	int	current_bit;

	max_bits = get_max_bits(data->size);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		// if (is_sorted(data->stack_a))
		// 	return ;
		radix_sort_bit(data, current_bit, data->size);
		current_bit++;
	}
}
