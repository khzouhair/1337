# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khzouhai <khzouhai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 19:39:38 by khzouhai          #+#    #+#              #
#    Updated: 2024/11/30 11:42:40 by khzouhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
FILES=ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_putunsigned.c
OBJFILES=${FILES:%.c=%.o}
CC = cc
FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME}: ${OBJFILES}
	ar rc ${NAME} ${OBJFILES}
	
%.o: %.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@

fclean : clean
	rm -rf ${NAME}
	
clean : 
	rm -rf ${OBJFILES}
	
re : fclean all

.PHONY : clean