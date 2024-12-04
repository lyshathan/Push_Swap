/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:23:50 by lthan             #+#    #+#             */
/*   Updated: 2024/12/04 17:28:18 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_populate_list(char **tab, size_t index, t_stack **stack_a)
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
		ft_stack_add_back(stack_a, ft_stack_new(tmp));
		index++;
	}
}

void	set_stack(int arc, char **arv, t_stack **stack_a)
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

int	ft_push_swap(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	set_stack(arc, arv, &stack_a);
	if (!stack_a)
		return (0);
	ft_printf("Initial stacks =======\n");
	ft_stack_print(stack_a, stack_b);
	ft_sort_algo(&stack_a, &stack_b);
	ft_stack_print(stack_a, stack_b);
	return (1);
}

int	main(int arc, char **arv)
{
	(void)arc;
	if (!ft_push_swap(arc, arv))
		return (1);
	return (0);
}