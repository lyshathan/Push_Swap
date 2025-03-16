# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 14:55:30 by lthan             #+#    #+#              #
#    Updated: 2025/03/16 19:56:19 by ly-sha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = push_swap
RM = rm -rf

HEADERS = includes/ft_push_swap.h

SRCS_DIR = srcs
SRC = $(SRCS_DIR)/ft_push_swap.c \
	$(SRCS_DIR)/ft_check_input.c \
	$(SRCS_DIR)/ft_find_min_action_1.c \
	$(SRCS_DIR)/ft_find_min_action_2.c \
	$(SRCS_DIR)/ft_push_swap_utils.c \
	$(SRCS_DIR)/ft_push.c \
	$(SRCS_DIR)/ft_reverse_rotate.c \
	$(SRCS_DIR)/ft_rotate.c \
	$(SRCS_DIR)/ft_sort_algo.c \
	$(SRCS_DIR)/ft_sort_more_elem.c \
	$(SRCS_DIR)/ft_stack_management.c \
	$(SRCS_DIR)/ft_swap.c

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

OBJS_DIR = objects
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all:$(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT_FILES)
	make -C $(LIBFT_PATH)
	$(CC) $(SRC) $(CFLAGS) $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
