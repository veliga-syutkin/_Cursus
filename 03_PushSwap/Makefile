SOLVER =	main.c \
			check.c \
			dquote.c \
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
			stak_a.c \
			swap.c \

LIBFT_DIR = ./0_LIBFT/

SOLVER_DIR = ./1_SOLVER/

SRCS = $(addprefix $(SOLVER_DIR), $(SOLVER))

OBJS = $(SRCS:.c=.o)

AR = ./libft.a 

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(AR): $(OBJS) 
	make -C $(LIBFT_DIR) 

$(NAME): $(OBJS) $(AR) 
	$(CC) $(CFLAGS) $(OBJS) $(AR) -o $(NAME)

clean: 
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) 

fclean: clean 
	make -C $(LIBFT_DIR) fclean
	$(RM) $(AR) $(PARASITE) $(NAME)

mini: main clean

re: fclean all

exe: all
	./$(NAME)

leak: $(AR)
	g$(CC) $(CFLAGS) $(SRCS) $(AR) -o $(NAME) 
	valgrind -s --leak-check=full --show-leak-kinds=all ./push_swap 1 5

.PHONY: all clean fclean mini re exe