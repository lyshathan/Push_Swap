/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:23:50 by lthan             #+#    #+#             */
/*   Updated: 2024/12/02 10:21:40 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	set_stack(char **arv, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (arv[i] && is_number(arv[i]))
		i++;
	stack_a = malloc(i * sizeof(int));
	stack_b = malloc(i * sizeof(int));
	if (!stack_a || !stack_b)
		return (NULL);
	ft_bzero(stack_b, i * sizeof(int));
	i = 0;
	while (arv[i] && is_number(arv[i]))
	{
		stack_a[i] = ft_atoi(arv[i]);
		i++;
	}
}

void	ft_push_swap(char *arv, char *stack_a, char *stack_b)
{
	int	*stack_a;
	int	*stack_b;
	set_stack(arv, stack_a, stack_b);
}
