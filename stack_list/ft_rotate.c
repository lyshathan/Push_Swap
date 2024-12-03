/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:22:43 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 08:51:26 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		tmp = (*stack)->next;
		last->next = *stack;
		(*stack)->next = NULL;
		*stack = tmp;
	}
}

void	ft_rotate_a(t_list **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_list **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}