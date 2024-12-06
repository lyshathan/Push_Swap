/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:16:09 by lthan             #+#    #+#             */
/*   Updated: 2024/12/05 16:49:51 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*ft_find_pivot(t_stack *sorted)
{
	int	*pivot;
	int	i;
	int	pivot_number;
	int	size;
	int	result;
	
	size = ft_stack_size(sorted);
	if (size < 101)
	{
		pivot = malloc(4 * sizeof(int));
		if (!pivot)
			return (NULL);
		pivot[4] = 0;
		i = 0;
		pivot_number = 1;
		result = size / 4;
		if (size % 4 != 0)
			result++;
		while (sorted)
		{
			// ft_printf("node = %d	size = %d	i = %d	calcul = %d\n", *sorted->data, size, i, result * pivot_number);
			if (i == result * pivot_number)
			{
				pivot[pivot_number - 1] = *sorted->data;
				pivot_number++;
			}
			sorted = sorted->next;
			i++;
		}
	}
	i = 0;
	while (pivot[i])
	{
		ft_printf(RED"i = %d --> pivot = %d\n"RED, i, pivot[i]);
		i++;
	}
	return (pivot);
}

int	ft_find_rotation_iter(t_stack *stack_a, int pivot)
{
	int rotation;

	rotation = 0;
	while (stack_a)
	{
		if (*stack_a->data <= pivot)
			break ;
		stack_a = stack_a->next;
		rotation++;
	}
	if (rotation > ft_stack_size(stack_a))
		return (-1);
	ft_printf(GREEN"rotation = %d\n"RESET, rotation);
	return (rotation);
}

int	ft_find_rev_rotation_iter(t_stack *stack_a, int pivot)
{
	int rev_rotation;
	int	i;
	int	size;

	size = ft_stack_size(stack_a);
	rev_rotation = 0;
	i = 1;
	while (stack_a)
	{
		if (*stack_a->data <= pivot)
		{
			rev_rotation = i;
			// ft_printf("lower found = %d		at node = %d\n", *stack_a->data, i);
		}
		i++;
		stack_a = stack_a->next;
	}
	// ft_printf("size = %d	i = %d		before rev_rotation = %d\n", i, size, rev_rotation);
	rev_rotation = size - rev_rotation + 1;
	ft_printf(GREEN"rev_rotation = %d\n"RESET, rev_rotation);
	return (rev_rotation);
}

int	ft_find_rotation_side(t_stack *stack_a, int	pivot)
{
	int	rotation;
	int	rev_rotation;
	
	rotation = ft_find_rotation_iter(stack_a, pivot);
	// ft_printf(GREEN"rotation = %d\n"RESET, rotation);
	if (rotation < 0)
		return (-1);
	if (!rotation)
		return (0);
	rev_rotation = ft_find_rev_rotation_iter(stack_a, pivot);
	// ft_printf(GREEN"rev_rotation = %d\n"RESET, rev_rotation);
	if (rotation <= rev_rotation)
		return (1);
	else
		return (2);
}

void	ft_sort_by_group(t_stack **stack_a, t_stack **stack_b, t_stack *sorted, int	*pivot)
{
	int i;
	int	side_rot;
	
	i = 0;
	int piv = 50;
	ft_printf(RED"pivot = %d\n"RESET, piv);
	side_rot = ft_find_rotation_side(*stack_a, piv);
	ft_printf(YELLOW"pivot = %d		rotation side = %d\n"RESET, pivot[i], side_rot);
	
	/* while (*stack_a && stack_a && pivot[i])
	{
		ft_printf(RED"OK OK\n"RESET);
		side_rot = ft_find_rotation_side(*stack_a, pivot[i]);
		ft_printf(RED"pivot = %d		rotation side = %d\n"RESET, pivot[i], side_rot);
		while (side_rot >= 0)
		{
			ft_printf(YELLOW"pivot = %d		rotation side = %d\n"RESET, pivot[i], side_rot);
			if (side_rot < 0)
				i++;
			ft_printf(YELLOW"data = %d		pivot = %d\n"RESET, *(*stack_a)->data, pivot[i]);
			while (*(*stack_a)->data > pivot[i])
			{
				if (side_rot == 1)
					ft_rotate_a(stack_a);
				if (side_rot == 2)
					ft_reverse_rotate_a(stack_a);
			}
			ft_push_b(stack_a, stack_b);
			ft_stack_print(*stack_a, *stack_b, sorted);
			side_rot = ft_find_rotation_side(*stack_a, pivot[i]);
			if (side_rot < 0)
				ft_printf(YELLOW"NUMBER NOT FOUND // pivot = %d	// rotation side = %d\n"RESET, pivot[i], side_rot);
		}
		i++;
	}
	 */
}

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b, t_stack *sorted)
{
	int	*pivot;
	
	pivot = ft_find_pivot(sorted);
	ft_sort_by_group(stack_a, stack_b, sorted, pivot);
}