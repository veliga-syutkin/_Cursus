NAME = libftprintf.a

SRCS =	ft_flags.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_puthexl_fd.c \
		ft_puthexu_fd.c \
		ft_putnbr_fd.c \
		ft_putunbr_fd.c \
		ft_putptr_fd.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_flags_combined.c \
		ft_flags_part1.c \
		ft_flags_part2.c \
		ft_isdigit.c \
		ft_utils.c \

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PARASITE = a.out

MAIN = main.c

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean 
	$(RM) $(NAME) $(PARASITE)

re: fclean all

main: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME)

.PHONY: all clean fclean re smain