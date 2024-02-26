SOLVER =	main.c \
			check.c \
			error.c \
			find_cost.c \
			list_utils.c \
			list.c \
			push.c \
			reset.c \
			rotate.c \
			setup.c \
			solve_3.c \
			solve.c \
			swap.c

SOLVER_DIR = ./1_SOLVER/

SRCS = $(addprefix $(SOLVER_DIR), $(SOLVER))

OBJS = $(SRCS:.c=.o)

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror -I$(SOLVER_DIR)

AR = ./0_LIBFT/libft.a

NAME = push_swap

$(NAME): $(OBJS)
	make -C ./0_LIBFT/
	$(CC) $(CFLAGS) $(OBJS) $(AR) -o $(NAME)

all: $(NAME)

clean: 
	make -C ./0_LIBFT/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./0_LIBFT/ fclean
	$(RM) $(NAME)

mini: main clean

re: fclean all

exe: main
	./$(EXE)

.PHONY: all clean fclean mini re