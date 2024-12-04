/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:09:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 16:33:26 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_print(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	

	if (stack_a || stack_b)
	{
		ft_printf(BLUE"stack A :\n");
		while (stack_a)
		{
			ft_printf("node #%d --> %d\n", i, *(int *)stack_a->data);
			stack_a = stack_a->next;
			i++;
		}
		ft_printf("\n");
		ft_printf(BLUE"stack B :\n");
		while (stack_b)
		{
			ft_printf("node #%d --> %d\n", j, *(int *)stack_b->data);
			stack_b = stack_b->next;
			j++;
		}
		ft_printf("\n");
	}
	ft_printf("\n"RESET);
}
