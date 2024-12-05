/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:16:09 by lthan             #+#    #+#             */
/*   Updated: 2024/12/05 09:33:45 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_top_stack_a(t_stack **stack)
{
	int	stack_1;
	int	stack_2;
	int	stack_last;
	
	if (!stack)
		return ;
	if (ft_stack_size(*stack) == 2)
	{
		stack_1 = *(* stack)->data;
		stack_2 = *(* stack)->next->data;
		if (stack_1 > stack_2)
			ft_swap_a(*stack);
	}
	if (ft_stack_size(*stack) > 2)
	{
		stack_1 = *(* stack)->data;
		stack_2 = *(* stack)->next->data;
		stack_last = *(ft_stack_last(*stack))->data;

		if (stack_1 < stack_2 && stack_1 < stack_last)
			return;
		else if (stack_last < stack_1 && stack_last < stack_2)
			ft_reverse_rotate_a(stack);
		else if (stack_2 < stack_1 && stack_2 < stack_last)
			ft_swap_a(*stack);
		return;
	}
}

void	ft_sort_top_stack_b(t_stack **stack)
{
	int	stack_1;
	int	stack_2;
	int	stack_last;
	
	if (!stack)
		return ;
	if (ft_stack_size(*stack) == 2)
	{
		stack_1 = *(* stack)->data;
		stack_2 = *(* stack)->next->data;
		if (stack_1 < stack_2)
			ft_swap_b(*stack);
	}
	if (ft_stack_size(*stack) == 3)
	{
		stack_1 = *(* stack)->data;
		stack_2 = *(* stack)->next->data;
		stack_last = *(* stack)->next->next->data;
		if (stack_1 < stack_2)
			ft_swap_b(*stack);
		if (stack_2 > stack_last)
		{
			ft_reverse_rotate_b(stack);
			if (stack_1 < stack_2)
				ft_swap_b(*stack);
		}
	}
	if (ft_stack_size(*stack) > 2)
	{
		stack_1 = *(* stack)->data;
		stack_2 = *(* stack)->next->data;
		stack_last = *(ft_stack_last(*stack))->data;

		if (stack_1 > stack_2 && stack_1 > stack_last)
			return;
		else if (stack_last > stack_1 && stack_last > stack_2)
			ft_reverse_rotate_b(stack);
		else if (stack_2 > stack_1 && stack_2 > stack_last)
			ft_swap_b(*stack);
		return;
	}
}

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
{
	while (!ft_is_sorted(*stack_a))
	{
		while (*stack_a && stack_a)
		{
			if (stack_a && *stack_a)
				ft_sort_top_stack_a(stack_a);
			if (stack_b && *stack_b)
				ft_sort_top_stack_b(stack_b);
			ft_push_b(stack_a, stack_b);
		}
		ft_stack_print(*stack_a, *stack_b);
		while (stack_b && *stack_b)
		{
			if (stack_b && *stack_b)
				ft_sort_top_stack_b(stack_b);
			if (stack_a && *stack_a)
				ft_sort_top_stack_a(stack_a);
			ft_push_a(stack_b, stack_a);
		}
		ft_stack_print(*stack_a, *stack_b);
	}
	
	
	// while (!ft_is_sorted(*stack_a))
	// {
	// 	ft_sort_top_stack(stack_a);
	// }
}