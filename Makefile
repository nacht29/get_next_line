TESTNAME = gnl.exe

SRC = 	$(wildcard *.c)

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

test: $(TESTNAME)

$(TESTNAME):
	$(CC) $(CFLAGS) $(SRC) -o $(TESTNAME) && ./$(TESTNAME)

clean:
	@$(RM) *.o
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(TESTNAME)
	@clear

re: fclean all

.PHONY: all test clean fclean re
