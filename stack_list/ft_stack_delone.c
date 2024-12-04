/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:01:52 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 10:29:15 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_delone(t_stack *stack, void (*del)(int*))
{
	if (!stack || !del)
		return ;
	del((void *)stack->data);
	free(stack);
}
