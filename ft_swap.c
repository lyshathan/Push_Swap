/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:57 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 10:27:31 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	*tmp;

	if (stack && stack->next)
	{
		tmp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = tmp;
	}
}

void	ft_swap_a(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ft_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
