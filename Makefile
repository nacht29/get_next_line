TESTNAME = gnl.exe

SRC = 	get_next_line.c \
		get_next_line_utils.c

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

test: $(TESTNAME)

$(TESTNAME):
	$(CC) $(CFLAGS) $(SRC) main.c -o $(TESTNAME) && ./$(TESTNAME) test.txt

clean:
	@$(RM) *.o
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(TESTNAME)
	@clear

re: fclean all

.PHONY: all test clean fclean re
