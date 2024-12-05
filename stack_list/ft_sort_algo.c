/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:08 by lthan             #+#    #+#             */
/*   Updated: 2024/12/05 10:20:36 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_2_elem(t_stack **stack_a)
{
	if (!ft_is_sorted(*stack_a))
		ft_rotate_a(stack_a);
}

void	ft_sort_3_elem(t_stack **stack_a)
{
	t_stack	*second;
	t_stack	*third;

	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (!ft_is_sorted(*stack_a))
	{
		if (*(*stack_a)->data > *(second)->data)
			ft_swap_a(*stack_a);
		if (*(second)->data > *(third)->data)
		{
			ft_reverse_rotate_a(stack_a);
			if (*(*stack_a)->data >
				*(*stack_a)->next->data)
				ft_swap_a(*stack_a);
		}
	}
}

void	ft_sort_4_elem(t_stack **stack_a, t_stack **stack_b)
{
	int		*little;
	int		place_in_stack;

	if (!ft_is_sorted(*stack_a))
	{
		ft_stack_find_little(*stack_a, &place_in_stack, &little);
		// ft_printf("little = %d		place in stack = %d\n", *little, place_in_stack);
		while (*(*stack_a)->data != *little)
		{
			if (place_in_stack > 3)
				ft_reverse_rotate_a(stack_a);
			else
				ft_rotate_a(stack_a);
		}
		ft_push_b(stack_a, stack_b);
		ft_sort_3_elem(stack_a);
		ft_push_a(stack_b, stack_a);
	}
}

void	ft_sort_5_elem(t_stack **stack_a, t_stack **stack_b)
{
	int		*little;
	int		place_in_stack;

	if (!ft_is_sorted(*stack_a))
	{
		ft_stack_find_little(*stack_a, &place_in_stack, &little);
		// ft_printf("little = %d		place in stack = %d\n", *little, place_in_stack);
		while (*(*stack_a)->data != *little)
		{
			if (place_in_stack > 3)
				ft_reverse_rotate_a(stack_a);
			else
				ft_rotate_a(stack_a);
		}
		ft_push_b(stack_a, stack_b);
		ft_sort_4_elem(stack_a, stack_b);
		ft_push_a(stack_b, stack_a);
	}
}



void	ft_sort_algo(t_stack **stack_a, t_stack **stack_b, t_stack *sorted)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(*stack_a);
	size_b = ft_stack_size(*stack_b);
	if (size_a == 2)
		ft_sort_2_elem(stack_a);
	if (size_a == 3)
		ft_sort_3_elem(stack_a);
	if (size_a == 4)
		ft_sort_4_elem(stack_a, stack_b);
	if (size_a == 5)
		ft_sort_5_elem(stack_a, stack_b);
	if (size_a > 5)
		ft_sort_more_elem(stack_a, stack_b, sorted);

}
