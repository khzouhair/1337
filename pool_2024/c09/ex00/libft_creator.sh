#!/bin/bash
gcc -Wall -Werror -Wextra -c *.c
ar rc -s libft.a *.o
rm -f *.o