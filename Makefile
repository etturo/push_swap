NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./ft_printf -I./checker_d/includes

NAME_BONUS = checker

SRCS = srcs/push_swap.c srcs/error_handler.c srcs/input_handler.c \
       srcs/stack_operations.c srcs/utils_functions.c srcs/stack_operations_2.c \
	   srcs/algorithm.c srcs/calculation.c srcs/calculation2.c \
	   srcs/math_functions.c srcs/sort_functions.c
SRCS_BONUS = checker_d/srcs/checker.c checker_d/srcs/error_handler.c \
			 checker_d/srcs/ft_strncmp.c checker_d/srcs/stack_operations.c \
			 checker_d/srcs/stack_operations_2.c checker_d/srcs/input_handler.c \
			 checker_d/srcs/utils_functions.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
PRINTF_LIB = ft_printf/libftprintf.a

all: $(PRINTF_LIB) $(NAME)

bonus: $(PRINTF_LIB) $(NAME_BONUS)

$(PRINTF_LIB):
	make -C ft_printf

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(PRINTF_LIB) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BONUS) $(PRINTF_LIB) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C ft_printf fclean

re: fclean all

RANGE ?= 0-500
COUNT ?= 500
RANDOM_NUMS = $$(echo "$(RANGE)" | awk -F'-' '{ \
	if (NF == 2) { lo=$$1; hi=$$2 } \
	else if (NF == 3 && $$1 == "") { lo=-$$2; hi=$$3 } \
	else if (NF == 4 && $$1 == "" && $$3 == "") { lo=-$$2; hi=-$$4 } \
	print lo, hi \
}' | xargs seq | shuf -n $(COUNT) | tr '\n' ' ')

test: $(NAME)
	@./$(NAME) $(RANDOM_NUMS)

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $$(echo "$(RANGE)" | awk -F'-' '{if (NF==2) {lo=$$1; hi=$$2} else if (NF==3 && $$1=="") {lo=-$$2; hi=$$3} else if (NF==4 && $$1=="" && $$3=="") {lo=-$$2; hi=-$$4} print lo, hi}' | xargs seq | shuf -n $(COUNT) | tr '\n' ' ')

.PHONY: all clean fclean re valgrind test
