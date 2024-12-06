/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:32 by lthan             #+#    #+#             */
/*   Updated: 2024/12/06 10:33:15 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b)->next;
		ft_stack_add_front(stack_a, *stack_b);
		tmp->prev = NULL;
		*stack_b = tmp;
	}
	ft_printf("pa\n");
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a)->next;
		ft_stack_add_front(stack_b, *stack_a);
		tmp->prev = NULL;
		*stack_a = tmp;
	}
	ft_printf("pb\n");
}