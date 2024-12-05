/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:09:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/05 10:01:44 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_print(t_stack *stack_a, t_stack *stack_b, t_stack *sorted)
{
	int	i;
	int	j;

	i = 1;
	j = 1;

	ft_printf(BLUE"stack A :			stack B :		sorted :\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("A_node	#%d --> %d		", i, *(int *)stack_a->data);
			stack_a = stack_a->next;
			i++;
		}
		else if (!stack_a)
			ft_printf("---------			");
		// ft_printf("\n");
		// ft_printf(BLUE"stack B :\n");
		if (stack_b)
		{
			ft_printf("B_node	#%d --> %d		", j, *(int *)stack_b->data);
			stack_b = stack_b->next;
			j++;
		}
		else if (!stack_b)
			ft_printf("---------		");
		// ft_printf("\n");
		if (sorted)
		{
			ft_printf("S_node	#%d --> %d\n", j, *(int *)sorted->data);
			sorted = sorted->next;
			j++;
		}
		else if (!sorted)
			ft_printf("---------\n");
	}
	ft_printf("\n"RESET);
}
