/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-06 10:24:42 by nayala            #+#    #+#             */
/*   Updated: 2025-11-06 10:24:42 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	process_quoted_arg(char *arg, int has_quoted_arg,
		int i, t_stack **s)
{
	if (has_quoted_arg || i > 1)
		return (0);
	if (!process_single_arg(arg, s))
		return (0);
	return (1);
}

int	process_individual_arg(char *arg, int has_quoted_arg, t_stack **s)
{
	if (has_quoted_arg)
		return (0);
	if (!process_normal_arg(arg, s))
		return (0);
	return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		has_quoted_arg;

	stack = NULL;
	has_quoted_arg = 0;
	i = 1;
	while (i < argc)
	{
		if (!process_arg(argv[i], has_quoted_arg, i, &stack))
			return (NULL);
		if (ft_strchr(argv[i], ' '))
			has_quoted_arg = 1;
		i++;
	}
	return (stack);
}

int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

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

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
