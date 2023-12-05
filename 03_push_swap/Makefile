LIBFT = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putunbr_fd.c \
		ft_puthexl_fd.c \
		ft_puthexu_fd.c \
		ft_putptr_fd.c \
		ft_printf.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		ft_lstadd_back.c \
		ft_lstadd_front_bonus.c \
		ft_lstadd_before_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstupdate.c \
		# ft_lstmap_bonus.c \

LSTUTILS =	pos_end.c \
			push.c \
			reverse.c \
			rotate.c \
			swap.c \

LIBFT_DIR = ./0_LIBFT/

LSTUTILS_dir = ./1_LSTUTILS/

SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT)) $(addprefix $(LSTUTILS_dir), $(LSTUTILS))

OBJS = $(SRCS:.c=.o)

AR = libft.a

RM = rm -f

CFLAGS =  -Wall -Wextra -Werror

PARASITE = a.out

MAIN = main.c

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