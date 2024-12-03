/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:50:39 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 09:07:14 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;
	// t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		before_last = *stack;
		while (before_last->next->next)
			before_last = before_last->next;
		last = ft_lstlast(*stack);
		before_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	ft_reverse_rotate_a(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}