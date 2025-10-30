/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 13:28:34 by nayala            #+#    #+#             */
/*   Updated: 2025-10-30 13:28:34 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

static int	get_min_position(t_stack *stack)
{
	int	min;
	int	position;
	int	i;

	min = get_min_value(stack);
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->value == min)
			position = i;
		stack = stack->next;
		i++;
	}
	return (position);
}