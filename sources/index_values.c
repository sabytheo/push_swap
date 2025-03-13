/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:08:38 by tsaby             #+#    #+#             */
/*   Updated: 2025/03/13 09:59:44 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	j;
	int	k;
	int	temp;

	j = 0;
	while (j < size - 1)
	{
		k = j + 1;
		while (k < size)
		{
			if (tab[j] > tab[k])
			{
				temp = tab[j];
				tab[j] = tab[k];
				tab[k] = temp;
			}
			k++;
		}
		j++;
	}
	return (tab);
}

int	*fill_tab(t_node **stack, int size)
{
	int		*tab;
	int		i;
	t_node	*current;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	current = *stack;
	while (current)
	{
		tab[i++] = current->value;
		current = current->next;
	}
	return (tab);
}

int	index_values(t_node *stack)
{
	int	*tab;
	int	size;
	int	i;

	size = stack_size(stack);
	if (size < 2)
		return (0);
	tab = fill_tab(&stack, size);
	if (!tab)
		return (free_stack(&stack), 0);
	tab = sort_tab(tab, size);
	while (stack)
	{
		i = 0;
		while (i <= size)
		{
			if (stack->value == tab[i++])
			{
				stack->value = i - 1;
				break ;
			}
		}
		stack = stack->next;
	}
	return (free(tab), 1);
}

int	is_sorted(t_node **stack_a)
{
	t_node *current;

	current = *stack_a;
	while(current->next)
	{
		if(current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}
