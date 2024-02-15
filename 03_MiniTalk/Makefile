MANDATORY_FILES =	send.c \

BONUS_FILES =	server_utils.c \

LIBFT_DIR = ./0_LIBFT/ 
MANDATORY_DIR = ./1_minitalk/
BONUS_DIR = ./2_minitalk_bonus/
DEBUG_DIR = ./3_minitalk_bonus_debug/

MANDATORY = $(MANDATORY_FILES:%=$(MANDATORY_DIR)%)
BONUS = $(BONUS_FILES:%=$(BONUS_DIR)%)
DEBUG = $(DEBUG_FILES:%=$(DEBUG_DIR)%)

OBJS = $(SRCS:.c=.o)

NAME = minitalk
CLIENT = client
SERVER = server

AR = ./0_LIBFT/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(AR) $(SERVER) $(CLIENT)

$(SERVER): $(SRV_SRC) $(AR)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(AR) -o $(SERVER)

$(CLIENT): $(CLI_SRC) $(AR)
	$(CC) $(CFLAGS) $(CLI_SRC) $(AR) -o $(CLIENT)

$(AR):
	make -C $(LIBFT_DIR)

bonus: $(AR) $(BONUS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS) ./2_minitalk_bonus/server_sigaction.c $(AR) -o $(SERVER)
	$(CC) $(CFLAGS) ./2_minitalk_bonus/client_sigaction.c $(AR) -o $(CLIENT)

debug: $(AR) $(DEBUG)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(DEBUG) ./3_minitalk_bonus_debug/server_sigaction.c $(AR) -o $(SERVER)
	$(CC) $(CFLAGS) ./3_minitalk_bonus_debug/client_sigaction.c $(AR) -o $(CLIENT)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all