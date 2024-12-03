/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:08 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 22:33:03 by ly-sha           ###   ########.fr       */
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
	t_list	*second;
	t_list	*third;

	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (!ft_is_sorted(*stack_a))
	{
		while (*(int *)(*stack_a)->content > *(int *)second->content ||
			*(int *)(*stack_a)->content > *(int *)third->content)
			ft_rotate_a(stack_a);
		ft_push_b(stack_a, stack_b);
		ft_sort_2_elem(stack_a);
		ft_push_a(stack_b, stack_a);
	}
}

void	ft_sort_4_elem(t_list **stack_a, t_list **stack_b)
{
	// while (!ft_is_sorted(*stack_a))
	// {
	// 	while (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
	// 		ft_rotate_a(stack_a);
	// 	ft_push_b(stack_a, stack_b);
	// 	ft_sort_3_elem(stack_a, stack_b);
	// 	ft_push_a(stack_b, stack_a);
	// }
}

// void	ft_sort_5_elem(t_list **stack_a, t_list **stack_b)
// {

// }

void	ft_sort_algo(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_b == 0)
	{
		if (size_a == 2)
			ft_sort_2_elem(stack_a);
		if (size_a == 3)
			ft_sort_3_elem(stack_a, stack_b);
		if (size_a == 4)
			ft_sort_4_elem(stack_a, stack_b);
	}

}
