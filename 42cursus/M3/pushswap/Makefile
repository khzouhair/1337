NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_atoi.c ft_split.c main.c utils_stack.c verify_inputs.c operations.c push_swap.c small_sort.c

OBJS = ${FILES:%.c=%.o}

all : ${NAME}
${NAME} : ${OBJS} 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	rm -rf ${NAME}

clean :
	rm -rf ${OBJS}  
	
re : fclean all

.PHONY : all fclean clean  re