/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:49:48 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/18 16:40:30 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

void	error_exit(t_data *data)
{
	if (data->stack_a)
		free_stack(&data->stack_a);
	if (data->stack_b)
		free_stack(&data->stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
