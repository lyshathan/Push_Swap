/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:40:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/03 09:07:21 by lthan            ###   ########.fr       */
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

void	ft_lstprint(t_list *stack);
void	ft_lstprint_stack(t_list *stack_a, t_list *stack_b);
long	ft_atoi_long(const char *nptr);
void	ft_swap_a(t_list *stack_a);
void	ft_swap_b(t_list *stack_b);
void	ft_swap_all(t_list *stack_a, t_list *stack_b);
void	ft_push_a(t_list **stack_b, t_list **stack_a);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_rotate_all(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a(t_list **stack_a);
void	ft_reverse_rotate_b(t_list **stack_b);
void	ft_reverse_rotate_all(t_list **stack_a, t_list **stack_b);

#endif