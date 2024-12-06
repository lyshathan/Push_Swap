/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:31:15 by lthan             #+#    #+#             */
/*   Updated: 2024/12/06 10:42:43 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	t_stack *tmp;
	
	if (new)
	{
		new->next = *stack;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;	
	}
}
