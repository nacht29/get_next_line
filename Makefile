NAME = gnl.exe

SRC = 	get_next_line.c \
		get_next_line_utils.c

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

test: $(NAME)

buf: 
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRC) main.c -o $(NAME) && ./$(NAME) test.txt | cat -e

$(NAME):
	$(CC) $(CFLAGS) $(SRC) main.c -o $(NAME) && ./$(NAME) test.txt | cat -e

clean:
	@$(RM) *.o *.out
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@clear

re: fclean all

.PHONY: all test clean fclean re
