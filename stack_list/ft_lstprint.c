/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:09:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/02 12:50:11 by lthan            ###   ########.fr       */
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