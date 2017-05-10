# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upierre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 12:19:19 by upierre-          #+#    #+#              #
#    Updated: 2017/05/10 12:24:15 by upierre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
CCFLAGS = -Werror -Wextra -Wall
FRMW = -framework OpenGL -framework -Appkit

D_SRC = src
D_MLX = minilibx_macos

LDL = $(addprefix -L, $(D_LIBFT))
LDM = $(addprefix -L, $(D_MLX))

F_SRC = main.c\


