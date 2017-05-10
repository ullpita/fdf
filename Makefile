# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upierre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 12:19:19 by upierre-          #+#    #+#              #
#    Updated: 2017/05/10 14:21:20 by upierre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
CCFLAGS = -Werror -Wextra -Wall
FRMW = -framework OpenGL -framework Appkit

D_SRC = src
D_INC = inc
D_OBJ = obj
D_LIBFT = libft
D_MLX = minilibx_macos

LDL = $(addprefix -L, $(D_LIBFT))
LDM = $(addprefix -L, $(D_MLX))

F_SRC = main.c\

.PHONY: make all fclean re

F_OBJ = $(addsuffix .o, $(basename $(F_SRC)))

DF_SRC = $(addprefix $(D_SRC)/, $(F_SRC))
DF_OBJ = $(addprefix $(D_OBJ)/, $(F_OBJ))

RM = /bin/rm -rf

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
		@mkdir -p $(D_OBJ) 2> /dev/null || true
		@echo "$(LOG_CYAN)$(NAME)... $(LOG_NOCOLOR)$<"
		@$(CC) $(CCFLAGS) -I $(D_INC) -o $@ -c $<

$(NAME): $(DF_OBJ)
		@make -C $(D_LIBFT)
		@make -C $(D_MLX)
		@echo "$(LOG_CYAN)$(NAME)... assembling...$(LOG_NOCOLOR)"
		@$(CC) $(LDL) -lft $(LDM) -lmlx $^ -o $@ $(FRMW)
		@echo "$(LOG_GREEN)$(NAME)... compiled ✓$(LOG_NOCOLOR)"

clean:
		@echo "$(LOG_RED)Deleting FdF's objs ✖$(LOG_NOCOLOR)"
		@$(RM) $(D_OBJ)

fclean: clean
		@echo "$(LOG_RED)Deleting FdF ✖$(LOG_NOCOLOR)"
		@$(RM) $(NAME)

re: fclean all
