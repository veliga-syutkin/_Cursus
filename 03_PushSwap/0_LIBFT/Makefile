LIBFT =	ft_atoi.c \
		ft_isdigit.c \
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

SRCS = $(LIBFT)

OBJS = $(SRCS:.c=.o)

AR = libft.a 

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

.c.o: 
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(AR)

$(AR): $(OBJS) 
	ar rcs ../$(AR) $(OBJS) 

clean: 
	$(RM) $(OBJS) 

fclean: clean 
	$(RM) $(AR)

mini: main clean

re: fclean all

.PHONY: all clean fclean mini re