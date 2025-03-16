/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_action_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:17:53 by lthan             #+#    #+#             */
/*   Updated: 2024/12/09 12:38:18 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_optimize_rot(int rot, int rev, int action_a)
{
	int	tmp_rot;
	int	tmp_rev;

	tmp_rev = rev;
	if (action_a < 0)
	{
		if (ft_abs(action_a) > ft_abs(tmp_rev))
			tmp_rev = 0;
		else
			tmp_rev = tmp_rev - action_a;
	}
	tmp_rot = rot;
	if (action_a > 0)
	{
		if (action_a > rot)
			tmp_rot = 0;
		else
			tmp_rot = tmp_rot - action_a;
	}
	if (-tmp_rev < tmp_rot)
		return (rev);
	return (rot);
}

int	min_rot_b(t_stack *stack, int number)
{
	int		rot;
	t_stack	*tmp;

	tmp = stack->next;
	rot = 1;
	while (tmp)
	{
		if ((number > *tmp->data && number < *tmp->prev->data)
			|| (nb_is_lower(number, tmp) && *tmp->data > *tmp->prev->data)
			|| (nb_is_upper(number, tmp) && *tmp->data > *tmp->prev->data))
			break ;
		rot++;
		tmp = tmp->next;
	}
	if (rot == ft_stack_size(stack))
		rot = 0;
	return (rot);
}

int	min_rev_b(t_stack *stack, int number)
{
	int		rev;
	t_stack	*tmp;

	tmp = ft_stack_last(stack);
	rev = -1;
	while (tmp->prev)
	{
		if ((number > *tmp->data && number < *tmp->prev->data)
			|| (nb_is_lower(number, tmp) && *tmp->data > *tmp->prev->data)
			|| (nb_is_upper(number, tmp) && *tmp->data > *tmp->prev->data))
			break ;
		rev--;
		tmp = tmp->prev;
	}
	if (ft_abs(rev) == ft_stack_size(stack))
		rev = 0;
	return (rev);
}

int	ft_min_act_b(t_stack *stack, int number, int action_a)
{
	int		rot;
	int		rev;

	if (number > *stack->data && number < *ft_stack_last(stack)->data)
		return (0);
	rot = min_rot_b(stack, number);
	rev = min_rev_b(stack, number);
	return (ft_optimize_rot(rot, rev, action_a));
}
