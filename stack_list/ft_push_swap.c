/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:23:50 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 09:08:41 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	set_list(char **arv, t_list **stack_a)
{
	int	i;
	int	*tmp;

	i = 1;
	while(arv[i] && is_number(arv[i]) && !is_overflow(arv[i]))
	{
		// ft_printf("%s --> result : %d\n", arv[i], is_number(arv[1]));
		tmp = malloc(sizeof(int));
		if (!tmp)
			return;
		*tmp = ft_atoi(arv[i]);
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
		i++;
	}
}



void	ft_push_swap(char **arv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	set_list(arv, &stack_a);
	ft_lstprint_stack(stack_a, stack_b);

	ft_printf("push =======\n");
	ft_push_a(&stack_b, &stack_a);
	ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_lstprint_stack(stack_a, stack_b);

	ft_printf("swap =======\n");
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	ft_swap_all(stack_a, stack_b);
	ft_lstprint_stack(stack_a, stack_b);

	ft_printf("rotate =======\n");
	ft_rotate_a(&stack_a);
	ft_rotate_b(&stack_b);
	ft_lstprint_stack(stack_a, stack_b);
	ft_rotate_all(&stack_a, &stack_b);
	ft_lstprint_stack(stack_a, stack_b);

	ft_printf("reverse rotate =======\n");
	ft_reverse_rotate_a(&stack_a);
	ft_reverse_rotate_b(&stack_a);
	ft_lstprint_stack(stack_a, stack_b);
	ft_reverse_rotate_all(&stack_b, &stack_a);
	ft_lstprint_stack(stack_a, stack_b);

}

int	main(int arc, char **arv)
{
	(void)arc;
	ft_push_swap(arv);
	return (0);
}