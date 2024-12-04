/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:08 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 21:49:07 by ly-sha           ###   ########.fr       */
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

// void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		*little;
// 	int		place_in_stack;

// 	if (!ft_is_sorted(*stack_a))
// 	{
// 		while (ft_stack_size(*stack_a) > 5)
// 		{
// 			ft_stack_find_little(*stack_a, &place_in_stack, &little);
// 			while (*(*stack_a)->data != *little)
// 			{
// 				if (place_in_stack > (ft_stack_size(*stack_a)/2))
// 					ft_reverse_rotate_a(stack_a);
// 				else
// 					ft_rotate_a(stack_a);
// 			}
// 			ft_push_b(stack_a, stack_b);
// 		}
// 		ft_sort_5_elem(stack_a, stack_b);
// 		while (ft_stack_size(*stack_b) != 0)
// 			ft_push_a(stack_b, stack_a);
// 	}
// }

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
{
	int		pivot;

	ft_printf("size = %d\n", ft_stack_size(*stack_a));
	while (ft_stack_size(*stack_a) > 5)
	{
		pivot = *ft_stack_last(*stack_a)->data;
		ft_printf(RED"data pivot = %d\n"RESET, *ft_stack_last(*stack_a)->data);
		ft_printf(RED"pivot = %d\n"RESET, pivot);
		while (*(*stack_a)->data != pivot)
		{
			if (*(*stack_a)->data < pivot)
				ft_push_b(stack_a, stack_b);
			else
				ft_rotate_a(stack_a);
		}
		ft_stack_print(*stack_a, *stack_b);
	}
	ft_sort_algo(stack_a, stack_b);
}

void	ft_sort_algo(t_stack **stack_a, t_stack **stack_b)
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
		ft_sort_more_elem(stack_a, stack_b);

}
