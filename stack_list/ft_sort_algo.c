/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:08 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 15:05:42 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_2_elem(t_list **stack_a)
{
	if (!ft_is_sorted(*stack_a))
		ft_rotate_a(stack_a);
}

void	ft_sort_3_elem(t_list **stack_a, t_list **stack_b)
{
	t_list *big;
	t_list	*current;

	big = *stack_a;
	current = *stack_a;
	while (big)
	{
		big = big->next;
	}
}

void	ft_sort_algo(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2 && ft_lstsize(*stack_b) == 0)
		ft_sort_2_elem(stack_a);
	if (ft_lstsize(*stack_a) == 3 && ft_lstsize(*stack_b) == 0)
		ft_sort_3_elem(stack_a, stack_b);
}