CC=cc 
CFLAGS=-Wall -Wextra -Werror
CLIENT=client
SERVER=server

all:$(CLIENT) $(SERVER)

%.o:%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT):client.o utils.o
	$(CC) $(CFLAGS) client.o utils.o -o $@

$(SERVER):server.o utils.o
	$(CC) $(CFLAGS) server.o utils.o -o $@

clean:
	rm -rf client.o server.o utils.o

fclean:clean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: clean