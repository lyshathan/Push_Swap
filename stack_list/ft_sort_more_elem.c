/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:16:09 by lthan             #+#    #+#             */
/*   Updated: 2024/12/06 14:20:50 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_count_until_top(t_stack *stack, int number)
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
	// ft_printf("number = %d		rot = %d		rev = %d\n", number, rot, rev);
	if (-rot < rev)
		return (rev);
	return (rot);
}

int	ft_count_set_b(t_stack *stack, int number, int action_a)
{
	int	rot;
	int	rev;
	t_stack	*current;

	if (number > *stack->data && number > *ft_stack_last(stack)->data)
	{
		// ft_printf("no need to sort B\n");
		return (0);
	}
	current = stack->next;
	rot = 1;
	while (current && number < *current->data)
	{
		rot++;
		current = current->next;
	}
	current = ft_stack_last(stack);
	rev = -1;
	while (current && number > *current->prev->data)
	{
		rev--;
		current = current->prev;
	}
	
	if (action_a < 0)
	{
		if (ft_abs(action_a) > ft_abs(rev))
			rev = 0;
		else
			rev = rev - action_a;
	}
	if (action_a > 0)
	{
		if (action_a > rot)
			rot = 0;
		else
			rot = rot - action_a;
	}
	if (-rev < rot)
	{
		// ft_printf("first good value found  = %d		rev = %d\n", *current->data, rev);
		return (rev);
	}
	// ft_printf("first good value found  = %d		rot = %d\n", *current->data, rot);
	return (rot);
}

int	ft_find_minimum_action(t_stack *stack_a, t_stack *stack_b, int number)
{
	int	action_a;
	int	action_b;
	int	total_action;
	
	action_a = ft_count_until_top(stack_a, number);
	// ft_printf(YELLOW"The shortest way up to stack A = %d\n"RESET, action_a);
	action_b = ft_count_set_b(stack_b, number, action_a);
	// ft_printf(YELLOW"The shortest way to set stack B = %d\n"RESET, action_b);
	total_action = ft_abs(action_a) + ft_abs(action_b) + 1;
	// ft_printf(RED"The minimum number of action for %d is	%d\n"RESET, number, total_action);
	return (total_action);
}

int	ft_find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest;
	int	 	min_current;
	int		min_next;
	t_stack	*current;
	
	current = stack_a;
	cheapest = *current->data;
	while (current->next)
	{
		min_current = ft_find_minimum_action(stack_a, stack_b, cheapest);
		min_next = ft_find_minimum_action(stack_a, stack_b, *current->next->data);
		ft_printf(YELLOW"min for %d --> %d	VS	min for %d --> %d\n"RESET, cheapest, min_current, *current->next->data, min_next);

		if (min_current > min_next)
		{
			cheapest = *current->next->data;
			ft_printf(GREEN"New chepeast found --> %d		\n"RESET, cheapest);
		}
		current = current->next;
	}
	ft_printf(GREEN"The cheapest is = %d\n"RESET, cheapest);
	return (cheapest);
}

void	ft_push_cheapest(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
	
}

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
{
	int cheapeast;
	
	//Find the minimum operations for a given number
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	// ft_push_b(stack_a, stack_b);
	ft_printf("To be sort =======\n");
	ft_stack_print(*stack_a, *stack_b);
	
	// ft_find_minimum_action(*stack_a, *stack_b, 238);
	cheapeast = ft_find_cheapest(*stack_a, *stack_b);
}