void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
{
	int		pivot;

	ft_printf("size = %d\n", ft_stack_size(*stack_a));
	while (ft_stack_size(*stack_a) > 5)
	{
		pivot = *ft_stack_last(*stack_a)->data;
		ft_printf(RED"data pivot = %d\n"RESET, *ft_stack_last(*stack_a)->data);
		ft_printf(RED"pivot = %d\n"RESET, pivot);
		while (*(*stack_a)->data != pivot)
		{
			if (*(*stack_a)->data < pivot)
				ft_push_b(stack_a, stack_b);
			else
				ft_rotate_a(stack_a);
		}
		ft_stack_print(*stack_a, *stack_b);
	}
	ft_sort_algo(stack_a, stack_b);
}

void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b)
{
	int		*little;
	int		place_in_stack;

	if (!ft_is_sorted(*stack_a))
	{
		while (ft_stack_size(*stack_a) > 5)
		{
			ft_stack_find_little(*stack_a, &place_in_stack, &little);
			while (*(*stack_a)->data != *little)
			{
				if (place_in_stack > (ft_stack_size(*stack_a)/2))
					ft_reverse_rotate_a(stack_a);
				else
					ft_rotate_a(stack_a);
			}
			ft_push_b(stack_a, stack_b);
		}
		ft_sort_5_elem(stack_a, stack_b);
		while (ft_stack_size(*stack_b) != 0)
			ft_push_a(stack_b, stack_a);
	}
}