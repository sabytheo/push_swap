/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:32:11 by tsaby             #+#    #+#             */
/*   Updated: 2025/02/15 11:40:23 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_swap(t_node **stack_a, t_node **stack_b)
{
	push_a(stack_b, stack_a);
	push_b(stack_a, stack_b);
	ft_printf("ss\n");
}

void	both_rotate(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}

void	both_reverse_rotate(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}

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
