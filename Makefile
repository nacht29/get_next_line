NAME = gnl.exe
BNAME = gnl_bonus.exe

SRC = 	get_next_line.c \
		get_next_line_utils.c

BSRC =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -g -pg

test: 
	$(CC) $(CFLAGS) $(SRC) main.c -o $(NAME) && ./$(NAME) test.txt | cat -e

buf: 
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRC) main.c -o $(NAME) && ./$(NAME) test.txt | cat -e

b-test:
	$(CC) $(CFLAGS) $(BSRC) b-main.c -o $(BNAME) && ./$(BNAME) t1.txt t2.txt | cat -e

b-buf:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(BSRC) b-main.c -o $(BNAME) && ./$(BNAME) t1.txt t2.txt | cat -e

val:
	valgrind --leak-check=yes ./gnl.exe test.txt

b-val:
	valgrind --leak-check=yes ./$(BNAME) t1.txt t2.txt

fclean:
	@$(RM) $(NAME) $(BNAME)
	@clear

re: fclean all

.PHONY: all test fclean re b-test b-buf
