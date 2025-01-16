/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:04:54 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/01/16 16:18:54 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Pushes the top element from the source stack to the destination stack
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

// Pushes the top element from staack b to stack a
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

// Pushes the top element from stack a to stack b
void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
