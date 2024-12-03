/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:09:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 08:12:07 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lstprint(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("node #%d --> %d\n", i, *(int *)stack->content);
		stack = stack->next;
		i++;
	}
}

void	ft_lstprint_stack(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf(BLUE"stack A :		stack B :\n");
	ft_printf("=========		=========\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("node #%d --> %d		", i, *(int *)stack_a->content);
			stack_a = stack_a->next;
			i++;

		}
		if (stack_b)
		{
			ft_printf("node #%d --> %d", j, *(int *)stack_b->content);
			stack_b = stack_b->next;
			j++;
		}
		ft_printf("\n");
	}
	ft_printf("\n"RESET);
}