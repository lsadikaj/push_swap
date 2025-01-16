/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:41:27 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/01/16 17:45:10 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Reverse rotates the stack, moving the last node to the top
static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

// Reverse rotates stack a
void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

// Reverse rotates stack b
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

// Reverse rotates botch stack a and stack b simultaneously
void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
