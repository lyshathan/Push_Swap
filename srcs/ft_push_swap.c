/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:23:50 by lthan             #+#    #+#             */
/*   Updated: 2024/12/09 15:09:42 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_print(t_stack *stack_a, t_stack *stack_b);

int	ft_populate_list(char **split, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i], stack_a))
			return (0);
		ft_stack_add_back(stack_a, ft_stack_new(ft_atoi(split[i])));
		i++;
	}
	return (1);
}

int	set_stack(char **arv, t_stack **stack_a)
{
	int		i;
	int		j;
	int		populate;
	char	**split;

	i = 1;
	while (arv[i])
	{
		split = ft_split(arv[i], ' ');
		if (!split)
			return (0);
		populate = ft_populate_list(split, stack_a);
		j = 0;
		while (split[j])
		{
			free(split[j]);
			j++;
		}
		free(split);
		split = NULL;
		if (!populate)
			return (0);
		i++;
	}
	return (1);
}

int	ft_push_swap(char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	set_stack(arv, &stack_a);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_sort_algo(&stack_a, &stack_b);
	if (stack_a)
	{
		ft_stack_clear(&stack_a, &del_content);
		free(stack_a);
		stack_a = NULL;
	}
	if (stack_b)
	{
		ft_stack_clear(&stack_b, &del_content);
		free(stack_b);
		stack_b = NULL;
	}
	return (1);
}

int	main(int arc, char **arv)
{
	if (arc < 2)
		return (1);
	if (!ft_push_swap(arv))
		return (1);
	return (0);
}
