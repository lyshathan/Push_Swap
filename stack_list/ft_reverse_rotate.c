/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:50:39 by lthan             #+#    #+#             */
/*   Updated: 2024/12/06 10:39:18 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*stack && (*stack)->next)
	{
		before_last = *stack;
		while (before_last->next->next)
			before_last = before_last->next;
		last = ft_stack_last(*stack);
		before_last->next = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
		(*stack)->prev = NULL;
	}
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}