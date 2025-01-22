/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:11:51 by lsadikaj          #+#    #+#             */
/*   Updated: 2025/01/22 16:41:18 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Free the memory allocated for the split array
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Handle the sorting logic based on the length of stack a
void	handle_sorting(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

// Handle the input arguments and split them if necessary
int	handle_input(int argc, char ***argv, char ***split_argv)
{
	if (argc == 1 || (argc == 2 && !(*argv)[1][0]))
		return (1);
	else if (argc == 2)
	{
		*split_argv = split((*argv)[1], ' ');
		*argv = *split_argv;
	}
	return (0);
}

// Main function to initialize stacks and start the sorting process
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;

	a = NULL;
	b = NULL;
	split_argv = NULL;
	if (handle_input(argc, &argv, &split_argv))
		return (1);
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
		handle_sorting(&a, &b);
	free_stack(&a);
	if (split_argv)
		free_split(split_argv);
	return (0);
}
