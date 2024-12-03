/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:23:50 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 14:53:08 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_populate_list(char **tab, size_t index, t_list **stack_a)
{
	int	*tmp;

	while (tab[index])
	{
		if (!is_valid_input(tab[index], stack_a))
			return ;
		tmp = malloc(sizeof(int));
		if (!tmp)
			return ;
		*tmp = ft_atoi(tab[index]);
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
		index++;
	}
}

void	set_list(int arc, char **arv, t_list **stack_a)
{
	char	**split;

	if (arc == 2)
	{
		split = ft_split(arv[1], ' ');
		ft_populate_list(split, 0, stack_a);
	}
	else
		ft_populate_list(arv, 1, stack_a);
}

void	ft_push_swap(int arc, char **arv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	set_list(arc, arv, &stack_a);
	if (!stack_a)
		return ;
	ft_printf("Initial stacks =======\n");
	ft_lstprint_stack(stack_a, stack_b);
	int sorted = ft_is_sorted(stack_a);
	ft_printf("Is sorted = %d\n", sorted);
	ft_sort_algo(&stack_a, &stack_b);
	ft_lstprint_stack(stack_a, stack_b);

	// ft_printf("push =======\n");
	// ft_push_a(&stack_b, &stack_a);
	// ft_push_b(&stack_a, &stack_b);
	// ft_push_b(&stack_a, &stack_b);
	// ft_lstprint_stack(stack_a, stack_b);

	// ft_printf("swap =======\n");
	// ft_swap_a(stack_a);
	// ft_swap_b(stack_b);
	// ft_swap_all(stack_a, stack_b);
	// ft_lstprint_stack(stack_a, stack_b);

	// ft_printf("rotate =======\n");
	// ft_rotate_a(&stack_a);
	// ft_rotate_b(&stack_b);
	// ft_lstprint_stack(stack_a, stack_b);
	// ft_rotate_all(&stack_a, &stack_b);
	// ft_lstprint_stack(stack_a, stack_b);

	// ft_printf("reverse rotate =======\n");
	// ft_reverse_rotate_a(&stack_a);
	// ft_reverse_rotate_b(&stack_a);
	// ft_lstprint_stack(stack_a, stack_b);
	// ft_reverse_rotate_all(&stack_b, &stack_a);
	// ft_lstprint_stack(stack_a, stack_b);

}

int	main(int arc, char **arv)
{
	(void)arc;
	ft_push_swap(arc, arv);
	return (0);
}