NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = array_check.c \
        init_stack.c \
        main.c      \
        manual.c    \
        m_sort.c    \
        parser.c    \
        sort.c      \
        stack_operations_2.c \
        stack_operations.c  

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    @$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.c.o:
    @$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
    @$(RM) $(OBJS)

fclean: clean
    @$(RM) $(NAME)

re: fclean all

.PHONY : fclean re clean all