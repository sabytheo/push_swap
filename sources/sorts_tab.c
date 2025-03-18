/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:12:38 by tsaby             #+#    #+#             */
/*   Updated: 2025/03/18 10:11:06 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next && (*stack_a)->next->next)
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->value > (*stack_a)->next->next->value)
			rotate_a(stack_a);
		else if ((*stack_a)->next->value > (*stack_a)->value
			&& (*stack_a)->next->value > (*stack_a)->next->next->value)
			reverse_rotate_a(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
	}
}

void	four(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->value != 0)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	three(stack_a);
	push_a(stack_b, stack_a);
}

void	five(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->next->next->next->next->value == 0)
		reverse_rotate_a(stack_a);
	while ((*stack_a)->value != 0)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	while ((*stack_a)->value != 1)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	bits;
	int	shift;
	int	count;
	int	max;

	bits = 0;
	shift = 0;
	max = size - 1;
	while ((max) >> bits != 0)
		bits++;
	while (shift < bits)
	{
		count = size;
		while (count > 0)
		{
			if (((*stack_a)->value >> shift) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			count--;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
		shift++;
	}
}

void	sorts(t_node **stack_a, t_node **stack_b)
{
	if (stack_size((*stack_a)) == 2)
	{
		if (is_sorted(stack_a) == 1)
			rotate_a(stack_a);
		return ;
	}
	else if (stack_size((*stack_a)) == 3)
		return (three(stack_a));
	else if (stack_size((*stack_a)) == 4)
		return (four(stack_a, stack_b));
	else if (stack_size((*stack_a)) == 5)
		return (five(stack_a, stack_b));
	else
		return (radix_sort(stack_a, stack_b, stack_size((*stack_a))));
}
