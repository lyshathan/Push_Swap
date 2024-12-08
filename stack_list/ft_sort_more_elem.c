/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:16:09 by lthan             #+#    #+#             */
/*   Updated: 2024/12/08 19:04:04 by ly-sha           ###   ########.fr       */
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

int	ft_number_is_lower(int number, t_stack *current)
{
	if (number < *current->data && number < *current->prev->data)
		return (1);
	return (0);
}

int	ft_number_is_upper(int number, t_stack *current)
{
	if (number > *current->data && number > *current->prev->data)
		return (1);
	return (0);
}

int	ft_count_set_b(t_stack *stack, int number, int action_a)
{
	int	rot;
	int	rev;
	int	tmp_rot;
	int	tmp_rev;
	t_stack	*current;

	if (number > *stack->data && number < *ft_stack_last(stack)->data)
	{
		// ft_printf("no need to sort B\n");
		return (0);
	}
// find number of rotation needed
	current = stack->next;
	rot = 1;
	while (current)
	{
		// ft_printf("number = %d		VS compare = %d\n", number, *current->data);
		if ((number > *current->data && number < *current->prev->data) ||
			(ft_number_is_lower(number, current) && *current->data > *current->prev->data) ||
			(ft_number_is_upper(number, current) && *current->data > *current->prev->data))
			break;
		rot++;
		current = current->next;
	}
	if (rot == ft_stack_size(stack))
	{
		// ft_printf("NUMBER = %d	SIZE = %d	ROT = %d\n", number, ft_stack_size(stack), rot);
		rot = 0;
	}
	// ft_printf("ROT = %d\n", rot);

// find number of reverse needed
	current = ft_stack_last(stack);
	rev = -1;
	while (current->prev)
	{
		if ((number > *current->data && number < *current->prev->data) ||
			(ft_number_is_lower(number, current) && *current->data > *current->prev->data) ||
			(ft_number_is_upper(number, current) && *current->data > *current->prev->data))
			break;
		rev--;
		current = current->prev;
	}
	if (ft_abs(rev) == ft_stack_size(stack))
	{
		// ft_printf("NUMBER = %d	SIZE = %d	REV = %d\n", number, ft_stack_size(stack), rev);
		rev = 0;
	}
	// ft_printf("REV = %d\n", rev);

	// ft_printf("number = %d	|	rot = %d	|	rev = %d\n", number, rot, rev);


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


	// ft_printf(RED"The minimum number of action for	%d	is	%d\n"RESET, number, total_action);
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
		// ft_printf(YELLOW"min for %d --> %d	VS	min for %d --> %d\n"RESET, cheapest, min_current, *current->next->data, min_next);

		if (min_current > min_next)
		{
			cheapest = *current->next->data;
			// ft_printf(GREEN"New chepeast found --> %d		\n"RESET, cheapest);
		}
		current = current->next;
	}
	// ft_printf(GREEN"The cheapest is = %d\n"RESET, cheapest);
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
		ft_reverse_rotate_a(stack_b);
		if (*(*stack_b)->data < *(*stack_b)->next->data)
			ft_swap_b(*stack_b);
	}
}

void	ft_push_cheapest(t_stack **stack_a, t_stack **stack_b, int cheapest)
{
	int	action_a;
	int	action_b;
	int min_act;

	action_a = ft_count_until_top(*stack_a, cheapest);
	action_b = ft_count_set_b(*stack_b, cheapest, action_a);
	min_act = ft_find_minimum_action(*stack_a, *stack_b, cheapest);

	// ft_printf("cheapest = %d	action_a = %d		action_b = %d		minimum action = %d\n", cheapest, action_a, action_b, min_act);

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
	while (action_a < 0)
	{
		ft_reverse_rotate_a(stack_a);
		action_a++;
	}
	while (action_a > 0)
	{
		ft_rotate_a(stack_a);
		action_a--;
	}
	while (action_b < 0)
	{
		ft_reverse_rotate_b(stack_b);
		action_b++;
	}
	while (action_b > 0)
	{
		ft_rotate_b(stack_b);
		action_b--;
	}
	ft_push_b(stack_a, stack_b);
}
void	ft_push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	// int i = 3;
	while (*stack_b)
	{
		t_stack	*first = *stack_a;
		t_stack	*last = ft_stack_last(*stack_a);
		t_stack	*b = *stack_b;

		// ft_printf("[%d] b = %d, first = %d, last = %d\n", i, *b->data, *first->data, *last->data);
		while (!(*b->data < *first->data && *b->data > *last->data) &&
		!((*b->data < *first->data && *first->data < *last->data) ||
		(*b->data > *last->data && *first->data < *last->data)))
		{

			ft_reverse_rotate_a(stack_a);
			first = *stack_a;
			last = ft_stack_last(*stack_a);
			b = *stack_b;
			// ft_printf("--> [%d] b = %d, first = %d, last = %d\n", i, *b->data, *first->data, *last->data);

		}
		ft_push_a(stack_b, stack_a);
		// ft_stack_print(*stack_a, *stack_b);
		// i--;
	}
	// ft_stack_print(*stack_a, *stack_b);

	while (*(*stack_a)->data > *ft_stack_last(*stack_a)->data)
		ft_reverse_rotate_a(stack_a);
}

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
{
	int cheapeast;

	ft_set_initial_b(stack_a, stack_b);

	// ft_printf("To be sort =======\n");
	// ft_stack_print(*stack_a, *stack_b);

	while (ft_stack_size(*stack_a) > 3)
	{
		cheapeast = ft_find_cheapest(*stack_a, *stack_b);
		ft_push_cheapest(stack_a, stack_b, cheapeast);
		// ft_stack_print(*stack_a, *stack_b);
	}
	ft_sort_3_elem(stack_a);
	// ft_stack_print(*stack_a, *stack_b);
	ft_push_back_to_a(stack_a, stack_b);
	// ft_stack_print(*stack_a, *stack_b);

}
