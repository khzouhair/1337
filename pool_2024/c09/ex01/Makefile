
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = srcs

all : lib

lib : compiler
	ar rc -s libft.a *.o

compiler :
	${CC} ${FLAGS} -c -Iinclude ./${SRCS}/*.c

clean :
	rm -rf *.o

fclean : clean
	rm -rf libft.a

re : fclean all

