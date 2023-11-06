NAME = libftprintf.all

SRCS =	ft_flags.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_puthexl_fd.c \
		ft_puthexu_fd.c \
		ft_putnbr_fd.c \
		ft_putunbr_fd.c \
		ft_strlen.c \
		ft_putptr.c \

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

main: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME)

