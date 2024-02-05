CC			:=	gcc
RM			:=	rm -rf
NAME		:=	asm++
CFLAGS		:=	-Wall -Wextra -Werror -ansi -pedantic -g --coverage
CPPFLAGS	:=	-Iinclude
SRCS		:=	$(shell find src -type f -name '*.c')
OBJS		:=	$(SRCS:.c=.o)
TESTS_SRCS	:=	$(shell find tests -type f -name 'tests_*.c')
VFLAGS		:=	-s                        	\
                --leak-check=full        	\
                --track-origins=yes        	\
                --read-var-info=yes        	\
                --trace-children=yes    	\
                --show-leak-kinds=all    	\
                --read-inline-info=yes    	\
                --errors-for-leak-kinds=all

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJS) main.c -o $(NAME)

unit_tests: $(OBJS)
	$(CC) $(CPPFLAGS) --coverage $(OBJS) $(TESTS_SRCS) -o unit_tests \
	-lcriterion

tests_run:	unit_tests
	./unit_tests
	gcovr -e tests .

valgrind:	unit_tests
	valgrind $(VFLAGS) ./unit_tests

clean:
	$(RM) $(OBJS)
	$(RM) $(shell find . -type f -name '*.gcno')
	$(RM) $(shell find . -type f -name '*.gcda')

fclean:	clean
	$(RM) $(NAME) ./unit_tests

re: fclean all

.PHONY: all tests8run clean fclean re
