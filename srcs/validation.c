/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 11:54:46 by nayala            #+#    #+#             */
/*   Updated: 2025-10-30 11:54:46 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) > INT_MAX ||  ft_atoi(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i )
	{
		/* code */
	}
	
}