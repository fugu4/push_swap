/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:56:15 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/18 16:39:59 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort_method(t_data *data)
{
	if (data->size <= 5)
		sort_small(data);
	else
		radix_sort(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.size = 0;
	if (!parse_args(&data, argc, argv))
		error_exit(&data);
	if (is_sorted(data.stack_a))
	{
		free_stack(&data.stack_a);
		return (0);
	}
	index_stack(data.stack_a);
	choose_sort_method(&data);
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (0);
}