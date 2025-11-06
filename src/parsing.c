/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-06 10:24:26 by nayala            #+#    #+#             */
/*   Updated: 2025-11-06 10:24:26 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	process_number(char *num_str, t_stack **stack)
{
	long	num;
	t_stack	*new_node;

	if (!is_valid_number(num_str))
		return (0);
	num = ft_atol(num_str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	new_node = stack_new((int)num);
	if (!new_node)
		return (0);
	stack_add_back(stack, new_node);
	return (1);
}

int	process_single_arg(char *arg, t_stack **stack)
{
	char	**numbers;
	int		i;
	int		success;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	success = 1;
	while (numbers[i] && success)
	{
		if (!process_number(numbers[i], stack))
			success = 0;
		i++;
	}
	ft_free_split(numbers);
	return (success);
}

int	process_normal_arg(char *arg, t_stack **stack)
{
	long	num;
	t_stack	*new_node;

	if (!is_valid_number(arg))
		return (0);
	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	new_node = stack_new((int)num);
	if (!new_node)
		return (0);
	stack_add_back(stack, new_node);
	return (1);
}
