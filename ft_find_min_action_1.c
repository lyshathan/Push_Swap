/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_action_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:31:47 by lthan             #+#    #+#             */
/*   Updated: 2024/12/09 11:18:44 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	nb_is_lower(int number, t_stack *current)
{
	if (number < *current->data && number < *current->prev->data)
		return (1);
	return (0);
}

int	nb_is_upper(int number, t_stack *current)
{
	if (number > *current->data && number > *current->prev->data)
		return (1);
	return (0);
}

int	ft_min_act_a(t_stack *stack, int number)
{
	int		rot;
	int		rev;
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	while (*current->data != number)
		current = current->next;
	tmp = current;
	rev = 0;
	while (tmp)
	{
		tmp = tmp->next;
		rev--;
	}
	tmp = current;
	rot = 0;
	while (tmp->prev)
	{
		tmp = tmp->prev;
		rot++;
	}
	if (-rot < rev)
		return (rev);
	return (rot);
}

int	ft_find_min_action(t_stack *stack_a, t_stack *stack_b, int number)
{
	int	action_a;
	int	action_b;
	int	total_action;

	action_a = ft_min_act_a(stack_a, number);
	action_b = ft_min_act_b(stack_b, number, action_a);
	if (action_a < 0 && action_b < 0)
	{
		if (ft_abs(action_a) > ft_abs(action_b))
			action_b = 0;
		else
			action_b = action_b - action_a;
	}
	if (action_a > 0 && action_b > 0)
	{
		if (action_a > action_b)
			action_b = 0;
		else
			action_b = action_b - action_a;
	}
	total_action = ft_abs(action_a) + ft_abs(action_b) + 1;
	return (total_action);
}
