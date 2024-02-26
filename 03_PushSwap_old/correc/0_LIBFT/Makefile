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

LIBFT_DIR = ./

SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT))

OBJS = $(SRCS:.c=.o)

NAME = libft.a 

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

mini: all clean

re: fclean all

exe: mini
	./$(EXE)

.PHONY: all clean fclean mini re exe