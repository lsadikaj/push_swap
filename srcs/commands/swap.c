/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:23:29 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/01/16 17:02:15 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Swaps the first two elements of the stack
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

// Swaps the first two element of stack a
void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

// Swaps the first two element of stack b
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

// Swaps the first two elements of both stacks simultaneously
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
