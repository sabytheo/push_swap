/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:24:21 by tsaby             #+#    #+#             */
/*   Updated: 2025/03/18 10:42:58 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	check_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (1);
	if (overflow_check(str) > 0)
		return (1);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	initialize_stack(int argc, char **argv, t_node **stack_a)
{
	t_node	*new_node;
	int		value;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		if (is_valid_number(argv[i]))
		{
			write(2, "Error\n", 7);
			free_stack(stack_a);
			return (1);
		}
		value = ft_atoi(argv[i]);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (1);
		new_node->value = value;
		new_node->next = *stack_a;
		*stack_a = new_node;
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (initialize_stack(argc, argv, &stack_a))
			return (0);
		if (check_duplicates(stack_a))
		{
			write(2, "Error\n", 7);
			free_stack(&stack_a);
			return (1);
		}
		if (!(index_values(stack_a)))
			return (free_stack(&stack_a), 0);
		if (is_sorted(&stack_a) == 0)
			return (free_stack(&stack_a), 0);
		sorts(&stack_a, &stack_b);
		free_stack(&stack_a);
	}
	else
		write(2, "Error\n", 7);
	return (0);
}
