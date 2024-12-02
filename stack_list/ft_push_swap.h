/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lthan <lthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:40:10 by lthan             #+#    #+#             */
/*   Updated: 2024/12/02 16:13:27 by lthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

void	ft_lstprint(t_list *stack);
long	ft_atoi_long(const char *nptr);
void	ft_swap_a(t_list *stack_a);
void	ft_swap_b(t_list *stack_b);
void	ft_swap_all(t_list *stack_a, t_list *stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);

#endif