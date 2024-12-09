# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lthan <lthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 14:55:30 by lthan             #+#    #+#              #
#    Updated: 2024/12/09 15:26:58 by lthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -rf

SRC = ft_push_swap.c \
ft_check_input.c \
ft_find_min_action_1.c \
ft_find_min_action_2.c \
ft_push_swap_utils.c \
ft_push.c \
ft_reverse_rotate.c \
ft_rotate.c \
ft_sort_algo.c \
ft_sort_more_elem.c \
ft_stack_management.c \
ft_swap.c

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FUNCTIONS = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

LIBFT_FILES = $(addprefix $(LIBFT_PATH)/, $(LIBFT_FUNCTIONS)) $(LIBFT_PATH)/libft.h $(LIBFT_PATH)/Makefile

all:$(NAME)

$(NAME): $(LIBFT_FILES) $(SRC) ft_push_swap.h Makefile
	make -C $(LIBFT_PATH)
	$(CC) $(SRC) $(CFLAGS) $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re