/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:57 by lthan             #+#    #+#             */
/*   Updated: 2024/12/02 16:06:40 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_a(t_list *stack_a)
{
	int	*tmp;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
	}
	ft_printf("sa\n");
}

void	ft_swap_b(t_list *stack_b)
{
	int	*tmp;

	if (stack_b && stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
	}
	ft_printf("sb\n");
}

void	ft_swap_all(t_list *stack_a, t_list *stack_b)
{
	int	*tmp;
	
	if (stack_a && stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
	}
	if (stack_b && stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
	}
	ft_printf("ss\n");
}
