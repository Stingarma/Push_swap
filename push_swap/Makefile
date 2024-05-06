# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 01:08:31 by lsaumon           #+#    #+#              #
#    Updated: 2024/04/09 13:13:03 by lsaumon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
LIBLIBA		:= libft/libft.a
LIBPRINTF	:= ./ft_printf
SRC			:= ./srcs

# =================================== SOURCES ==================================

SRCS		:= $(addprefix $(SRC)/, main.c) \
			   $(addprefix $(SRC)/, push_swap_utils.c) \
			   $(addprefix $(SRC)/, push_swap_utils2.c) \
			   $(addprefix $(SRC)/, push_swap_utils3.c) \
			   $(addprefix $(SRC)/, parsing.c) \

OBJ_DIR		:= .objs
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# =================================== FLAGS ====================================

CC			:=	cc
FLAGS		:=	-Wall -Wextra  -g3 -fsanitize=address -Werror
FLAGS		+=	-I libft -I includes
RM			:=	rm -rf

$(OBJ_DIR)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) -c $< -o $@

# =================================== COLORS ===================================

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN		:=	\033[1;36m

# =================================== COMPILATION ==============================

all:		$(NAME)

$(LIBLIBA):
	@make -s -C libft

$(NAME):	$(LIBLIBA) $(OBJS)
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBLIBA)
	@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# =================================== RULES ====================================

clean:

	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
	@make -s -C libft clean

fclean:		clean

	@ $(RM) $(NAME) $(RM)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
	@make -s -C libft fclean

re:		fclean all

.PHONY:		all bonus clean fclean re