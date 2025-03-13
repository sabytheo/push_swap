/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:14:18 by tsaby             #+#    #+#             */
/*   Updated: 2025/03/13 17:44:18 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// OPERATION

void				swap_a(t_node **stack_a);
void				swap_b(t_node **stack_b);
void				push_b(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **stack_b, t_node **stack_a);
void				rotate_a(t_node **stack_a);
void				rotate_b(t_node **stack_b);
void				reverse_rotate_a(t_node **stack_a);
void				reverse_rotate_b(t_node **stack_b);

// COMBINED_OPERATION

void				both_swap(t_node **stack_a, t_node **stack_b);
void				both_rotate(t_node **stack_a, t_node **stack_b);
void				both_reverse_rotate(t_node **stack_a, t_node **stack_b);

// UTILS

int					get_min(t_node *stack);
int					get_max(t_node *stack);
int					stack_size(t_node *stack);
void				print_stack(t_node *stack, char *name);
t_node				*get_last_node(t_node *stack);
void				free_stack(t_node **stack);

int					index_values(t_node *stack);
void				three(t_node **stack_a);
int					is_sorted(t_node **stack_a);
void				radix_sort(t_node **stack_a, t_node **stack_b, int size);
void				sorts(t_node **stack_a, t_node **stack_b);

#endif
