/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:51:38 by lthan             #+#    #+#             */
/*   Updated: 2024/12/06 10:28:47 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
	new->prev = last;
}
/* #include <stdio.h>
int	main(int arc, char **arv)
{
	int	*data;
	t_stack *stack;
	
	stack = NULL;

	int i = 1;
	while (arv[i])
	{
		data = malloc(sizeof(int));
		*data = atoi(arv[i]);
		ft_stack_add_back(&stack, ft_stack_new(data));
		i++;
	}
	t_stack *temp;
	temp = stack->next;
	while (temp)
	{
		printf("prev = %d	data = %d\n", *(temp)->prev->data, *(temp)->data);
		temp = temp->next;
	}
} */