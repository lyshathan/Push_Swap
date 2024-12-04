/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:46:49 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 13:33:09 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_find_little(t_stack *stack, int *place_in_stack, int **little)
{
	int i;

	i = 1;
	*little = stack->data;
	while (stack->next)
	{
		stack = stack->next;
		i++;
		if (**little > *(stack)->data)
		{
			*little = stack->data;
			*place_in_stack = i;
		}		
	}
}
