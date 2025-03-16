/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:16:09 by lthan             #+#    #+#             */
/*   Updated: 2024/12/09 10:53:42 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest;
	int		min_current;
	int		min_next;
	t_stack	*current;

	current = stack_a;
	cheapest = *current->data;
	while (current->next)
	{
		min_current = ft_find_min_action(stack_a, stack_b, cheapest);
		min_next = ft_find_min_action(stack_a, stack_b, *current->next->data);
		if (min_current > min_next)
			cheapest = *current->next->data;
		current = current->next;
	}
	return (cheapest);
}

void	ft_set_initial_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	if (*(*stack_b)->data < *(*stack_b)->next->data)
		ft_swap_b(*stack_b);
	if (*(*stack_b)->next->data < *(*stack_b)->next->next->data)
	{
		ft_reverse_rotate_b(stack_b);
		if (*(*stack_b)->data < *(*stack_b)->next->data)
			ft_swap_b(*stack_b);
	}
}

void	ft_rotate_stack(t_stack **s_a, t_stack **s_b, int act_a, int act_b)
{
	while (act_a < 0)
	{
		ft_reverse_rotate_a(s_a);
		act_a++;
	}
	while (act_a > 0)
	{
		ft_rotate_a(s_a);
		act_a--;
	}
	while (act_b < 0)
	{
		ft_reverse_rotate_b(s_b);
		act_b++;
	}
	while (act_b > 0)
	{
		ft_rotate_b(s_b);
		act_b--;
	}
}

void	ft_push_cheapest(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
	int	action_a;
	int	action_b;

	action_a = ft_min_act_a(*stack_a, cheapest);
	action_b = ft_min_act_b(*stack_b, cheapest, action_a);
	while (action_a < 0 && action_b < 0)
	{
		ft_reverse_rotate_all(stack_a, stack_b);
		action_a++;
		action_b++;
	}
	while (action_a > 0 && action_b > 0)
	{
		ft_rotate_all(stack_a, stack_b);
		action_a--;
		action_b--;
	}
	ft_rotate_stack(stack_a, stack_b, action_a, action_b);
	ft_push_b(stack_a, stack_b);
}

void	ft_push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*b;

	while (*stack_b)
	{
		first = *stack_a;
		last = ft_stack_last(*stack_a);
		b = *stack_b;
		while (!(*b->data < *first->data && *b->data > *last->data)
			&& !((*b->data < *first->data && *first->data < *last->data)
				|| (*b->data > *last->data && *first->data < *last->data)))
		{
			ft_reverse_rotate_a(stack_a);
			first = *stack_a;
			last = ft_stack_last(*stack_a);
			b = *stack_b;
		}
		ft_push_a(stack_b, stack_a);
	}
	while (*(*stack_a)->data > *ft_stack_last(*stack_a)->data)
		ft_reverse_rotate_a(stack_a);
}
