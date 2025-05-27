NAME = fractol
SRC = fractol.c mandelbrot.c julia.c utils1.c ft_atof.c utils2.c utils3.c utils4.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
MLX_PATH = ./include/minilibx
CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
