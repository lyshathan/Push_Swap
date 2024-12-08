/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:40:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/08 15:45:32 by ly-sha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

typedef struct s_stack
{
	int				*data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	ft_stack_print(t_stack *stack_a, t_stack *stack_b);
long	ft_atoi_long(const char *nptr);
int 	is_valid_input(char *str, t_stack **stack_a);

t_stack	*ft_stack_new(int *data);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_stack_add_front(t_stack **stack, t_stack *new);
void	ft_stack_delone(t_stack *stack, void (*del)(int *));
void	ft_stack_clear(t_stack **stack, void (*del)(int *));
int		ft_stack_size(t_stack *stack);


void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_all(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(t_stack **stack_b, t_stack **stack_a);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_all(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_all(t_stack **stack_a, t_stack **stack_b);

int		ft_is_sorted(t_stack *stack);
void	ft_stack_find_little(t_stack *stack, int *place_in_stack, int **little);
void	ft_sort_more_elem(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_3_elem(t_stack **stack_a);
void	ft_sort_algo(t_stack **stack_a, t_stack **stack_b);

#endif
