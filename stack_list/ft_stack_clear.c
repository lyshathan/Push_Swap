/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:38:32 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 10:28:35 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_clear(t_stack **stack, void (*del)(int *))
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !*stack || !del)
		return ;
	temp = *stack;
	while (temp)
	{
		del(temp->data);
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}
