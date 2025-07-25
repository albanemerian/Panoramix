##
## EPITECH PROJECT, 2025
## B-CCP-400-NAN-4-1-panoramix-albane.merian
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wshadow

LIBS = -lpthread -I./include

NAME = panoramix

TEST_NAME = unit_tests

TEST_FLAGS	=	--coverage -lcriterion

SRC = main.c \
	  src/parsing.c	\
	  src/helper.c	\
	  src/panoramix.c \
	  src/villager.c \
	  src/druid.c


SRCT = 	tests/test_parsing.c \
		tests/test_helper.c \
	  	tests/test_panoramix.c \
	  	tests/test_villager.c \
	  	tests/test_druid.c

TEST_SRC = 	  	src/parsing.c	\
	  			src/helper.c	\
	  			src/panoramix.c \
	  			src/villager.c \
	  			src/druid.c

OBJ = $(SRC:.c=.o)


RESET	=	\033[0m
GREEN	=	\033[1;92m
BLUE	 =	\033[1;94m
YELLOWBIG	=	\033[1;93m
RED			=	\033[1;91m



all: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJ) $(LIBS)
	@echo -e "$(GREEN)Compilation complete.$(RESET)"

re: fclean all


clean:
	@rm -f $(OBJ)
	@echo -e "$(BLUE)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(RED)Executable removed.$(RESET)"

unit_tests: clean unit_clean
	$(CC) -o $(TEST_NAME) $(SRCT) $(TEST_SRC) $(LIBS) $(TEST_FLAGS)

unit_clean:
	-@rm -rf *.gc*
	-@rm -rf *.gcov
	-@rm -f *.gcno *.gcda
	-@rm -f $(TEST_NAME)

tests_run: unit_tests
	@echo -e "$(YELLOW)Running tests...$(RESET)"
	@./$(TEST_NAME)

coverage: tests_run
	@gcovr --exclude tests/
	@gcovr --txt-metric branch --exclude tests/
