/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:43:26 by nayala            #+#    #+#             */
/*   Updated: 2025-10-30 10:43:26 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static void	init_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	int		i;
	int		*numbers;
	t_stack *new_node;

	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		error_exit(a, b);
	i = 0;
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		new_node = create_node(numbers[i]);
		if (!new_node)
		{
			free(numbers);
			error_exit(a, b);
		}
		add_node_back(a, new_node);
		i++;
	}
	if (has_duplicates(numbers, argc -1))
	{
		free(numbers);
		error_exit(a, b);
	}
	free(numbers);
}

static void	choose_sort(t_stack **a, t_stack **b)
{
	int size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!validate_args(argc, argv))
		error_exit(&a, &b);
	init_stacks(&a, &b, argc, argv);
	assign_indexes(a);
	choose_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}