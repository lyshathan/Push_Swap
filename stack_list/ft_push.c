/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:32 by lthan             #+#    #+#             */
/*   Updated: 2024/12/02 16:19:23 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		ft_lstadd_front(stack_a, tmp);
		*stack_b = (*stack_b)->next;
	}
	ft_printf("pa\n");
}