/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:39:40 by lthan             #+#    #+#             */
/*   Updated: 2024/12/09 14:17:09 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

long	ft_atoi_long(const char *nptr)
{
	size_t		i;
	long long	result;
	int			sign;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((long)result * sign);
}

int	ft_is_sorted(t_stack	*stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (*(int *)stack->data > *(int *)stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_stack_find_little(t_stack *stack, int *place_in_stack, int **little)
{
	int	i;

	i = 1;
	*little = stack->data;
	while (stack->next)
	{
		stack = stack->next;
		i++;
		if (**little > *(stack)->data)
		{
			*little = stack->data;
			*place_in_stack = i;
		}
	}
}

void	ft_stack_clear(t_stack **stack, void (*del)(int *))
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !*stack || !del)
		return ;
	temp = *stack;
	while (temp)
	{
		del(temp->data);
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}
