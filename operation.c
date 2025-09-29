/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:31:21 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 21:41:58 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	a->top = second;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	b->top = second;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || b->size == 0)
		return ;
	node = b->top;
	b->top = node->next;
	if (b->top)
		b->top->prev = NULL;
	b->size--;
	node->next = a->top;
	node->prev = NULL;
	if (a->top)
		a->top->prev = node;
	a->size++;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0)
		return ;
	node = a->top;
	a->top = node->next;
	if (a->top)
		a->top->prev = NULL;
	a->size--;
	node->next = b->top;
	node->prev = NULL;
	if (b->top)
		b->top->prev = node;
	b->top = node;
	b->size++;
	ft_putendl_fd("pb", 1);
}
