#include "push_swap.h"

int	get_min_value(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

// static int	count_smaller_values(t_stack *stack, int value)
// {
// 	int	count;

// 	count = 0;
// 	while (stack)
// 	{
// 		if (stack->value < value)
// 			count++;
// 		stack = stack->next;
// 	}
// 	return (count);
// }

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
