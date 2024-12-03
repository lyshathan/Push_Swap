/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:27:44 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 14:47:51 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	del_content(void *content)
{
	if(content)
		free(content);
}

int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}

int	is_overflow(char *str)
{
	if (ft_atoi_long(str) > INT_MAX || ft_atoi_long(str) < INT_MIN)
		return (1);
	else
		return (0);
}

int	is_double(t_list *stack, int nbr)
{
	while (stack)
	{
		if (nbr == *(int *)stack->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int is_valid_input(char *str, t_list **stack_a)
{
	if (!is_number(str) || is_overflow(str) || is_double(*stack_a, ft_atoi(str)))
	{
		write(2, "Error\n", 5);
		ft_lstclear(stack_a, &del_content);
		return (0);
	}
	return (1);
}
