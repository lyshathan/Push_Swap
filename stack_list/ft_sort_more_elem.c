/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:16:09 by lthan             #+#    #+#             */
/*   Updated: 2024/12/05 12:21:35 by lthan            ###   ########.fr       */
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
		ft_printf("i = %d --> pivot = %d\n", i, pivot[i]);
		i++;
	}
	return (pivot);
}
int	ft_find_rotation_iter(st_stack *stack_a, int pivot)
{
	int rotation;

	rotation = 0;
	while ()
	{
		
	}
}


int	ft_find_rotation_side(t_stack *stack_a, int	pivot)
{
	int	rotation;
	int	rev_rotation;
	
	rotation = ft_find_rotation_iter(t_stack *stack_a, int	pivot);
	if (!find_rotation_iter(stack_a, pivot))
		return (0);
	rev_rotation = ft_find_rev_rotation_iter(t_stack *stack_a, int	pivot);
	if (rotation < rev_rotation)
		return (1);
	else
		return (2);
}

void	ft_sort_by_group(t_stack **stack_a, t_stack **stack_b, t_stack *sorted, int	*pivot)
{
	int i;
	
	i = 0;
	// while (!stack_a)
	// {
		while (*(*stack)->data < pivot[i])
		{
			if (ft_find_rotation_side(*stack_a, pivot[i]) == 1)
				ft_rotate_a(stack_a);
			if (ft_find_rotation_side(*stack_a, pivot[i]) == 2)
				ft_reverse_rotate_a(stack_a);
		}
		ft_push_b(stack_a, stack_b);
		pivot++;
		
	// }
}

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b, t_stack *sorted)
{
	int	*pivot;
	
	pivot = ft_find_pivot(sorted);
	ft_sort_by_group(stack_a, stack_b, sorted, pivot);
}