/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:12:38 by tsaby             #+#    #+#             */
/*   Updated: 2025/02/18 09:56:10 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Final rotations to place the minimum value at the top of stack A.
* - Uses reverse rotations until the minimum value is at the top
*/
void	last_rotate(t_node **stack_a)
{
	while ((*stack_a)->value != get_min(*stack_a))
		reverse_rotate_a(stack_a);
}

/*
* Moves the appropriate element to the top of stack B.
* - Finds the first element in B larger than the last element in A
* - Chooses the most efficient rotation to move it to the top
* - Performs the necessary rotations
*/
void	move_value_to_top_b(t_node **stack_a, t_node **stack_b)
{
	int		y;
	t_node	*current;

	y = 0;
	current = *stack_b;
	while (current && current->value < get_last_node(*stack_a)->value)
	{
		y++;
		current = current->next;
	}
	if ((y <= stack_size(*stack_b) / 2) && (stack_size(*stack_b) > 0))
	{
		while (y > 0 && stack_size(*stack_b) > 0)
		{
			rotate_b(stack_b);
			y--;
		}
	}
	else
	{
		while (y++ < stack_size(*stack_b) && stack_size(*stack_b) > 0)
			reverse_rotate_b(stack_b);
	}
}

/*
* - Directly pushes elements in the expected order
* - Handles special cases for the largest elements
* - Reorganizes B if necessary to access desired elements
* - Finalizes the sorting of A once B is empty
*/
void	push_values_to_a(t_node **stack_a, t_node **stack_b, int i)
{
	while (stack_size(*stack_b) > 0)
	{
		if ((*stack_b)->value == i)
		{
			push_a(stack_b, stack_a);
			i--;
		}
		else if ((get_last_node(*stack_a)->value == (stack_size(*stack_b)
					+ stack_size(*stack_a)) - 1)
			|| ((*stack_b)->value > get_last_node(*stack_a)->value))
		{
			push_a(stack_b, stack_a);
			rotate_a(stack_a);
		}
		else if (get_last_node(*stack_a)->value == i)
		{
			reverse_rotate_a(stack_a);
			i--;
		}
		else
			move_value_to_top_b(stack_a, stack_b);
	}
	last_rotate(stack_a);
}

int	chunks(int count)
{
	double	chunks;

	chunks = (0.000000053 * (count * count)) + (0.03 * count) + 14.5;
	return ((int)chunks);
}

/*
* - Main fuction for sorting numbers
* - Calculates chunk size based on stack length
* - Pushes elements from A to B in chunks, keeping the 3 largest in A
* - Sorts the remaining 3 elements in A
* - Pushes and sorts elements from B back to A
*/
void	sorts_tab(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	chunk;

	len = stack_size(*stack_a);
	chunk = chunks(len);
	while (stack_size(*stack_b) < len - 3)
	{
		if ((*stack_a)->value <= stack_size(*stack_b) && (*stack_a)->value < len
			- 3)
		{
			push_b(stack_a, stack_b);
		}
		else if ((*stack_a)->value <= chunk + stack_size(*stack_b)
			&& (*stack_a)->value < len - 3)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
	three(stack_a);
	push_values_to_a(stack_a, stack_b, stack_size(*stack_b) - 1);
}
