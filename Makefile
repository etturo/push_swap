NAME = push_swap.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./ft_printf

SRCS = srcs/push_swap.c srcs/error_handler.c srcs/input_handler.c \
       srcs/stack_operations.c srcs/utils_functions.c srcs/stack_operations_2.c
OBJS = $(SRCS:.c=.o)
PRINTF_LIB = ft_printf/libftprintf.a

all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	make -C ft_printf

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

RANGE ?= -100-100
COUNT ?= 10
RANDOM_NUMS = $$(echo "$(RANGE)" | awk -F'-' '{ \
	if (NF == 2) { lo=$$1; hi=$$2 } \
	else if (NF == 3 && $$1 == "") { lo=-$$2; hi=$$3 } \
	else if (NF == 4 && $$1 == "" && $$3 == "") { lo=-$$2; hi=-$$4 } \
	print lo, hi \
}' | xargs seq | shuf -n $(COUNT) | tr '\n' ' ')

test: $(NAME)
	@./$(NAME) $(RANDOM_NUMS)

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(RANDOM_NUMS)

.PHONY: all clean fclean re valgrind test
