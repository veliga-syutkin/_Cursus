SOLVER =	check.c \
			error.c \
			find_cost.c \
			list_utils.c \
			list.c \
			push.c \
			reset.c \
			rotate.c \
			setup.c \
			rotate.c \
			setup.c \
			solve_3.c \
			solve.c \
			swap.c \

LIBFT =	ft_atoi.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_puthexl_fd.c \
		ft_puthexu_fd.c \
		ft_putnbr_fd.c \
		ft_putptr_fd.c \
		ft_putstr_fd.c \
		ft_putunbr_fd.c \
		ft_strlen.c \

LIBFT_DIR = ./0_LIBFT/

SOLVER_DIR = ./1_SOLVER/

SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT)) $(addprefix $(SOLVER_DIR), $(SOLVER))

OBJS = $(SRCS:.c=.o)

AR = libft.a 

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

PARASITE = a.out

MAIN = ./1_SOLVER/main.c

EXE = push_swap

.c.o: 
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

all: mini

$(AR): $(OBJS) 
	ar rcs $(AR) $(OBJS) 

clean: 
	$(RM) $(OBJS) 

fclean: clean 
	$(RM) $(AR) $(PARASITE) $(EXE)

mini: main clean

re: fclean all

main: $(AR)
	$(CC) $(CFLAGS) $(MAIN) $(AR) -o $(EXE)

exe: main
	./$(EXE)

.PHONY: all clean fclean mini re main exe