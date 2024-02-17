SERVER_MANDATORY = $(MANDATORY_DIR)server_sigaction.c
CLIENT_MANDATORY = $(MANDATORY_DIR)client_sigaction.c
SERVER_BONUS = $(BONUS_DIR)server_sigaction.c
CLIENT_BONUS = $(BONUS_DIR)client_receptive.c
SERVER_DEBUG = $(DEBUG_DIR)server_sigaction.c
CLIENT_DEBUG = $(DEBUG_DIR)client_sigaction.c

MANDATORY_FILES =	server_utils.c \

BONUS_FILES =	server_utils.c \

LIBFT_DIR = ./0_LIBFT/ 
MANDATORY_DIR = ./1_minitalk_mandatory/
BONUS_DIR = ./2_minitalk_bonus/
DEBUG_DIR = ./3_minitalk_bonus_debug/

MANDATORY = $(addprefix $(MANDATORY_DIR), $(MANDATORY_FILES))
BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
DEBUG = $(addprefix $(DEBUG_DIR), $(BONUS_FILES))

NAME = minitalk
CLIENT = client
SERVER = server

AR = ./0_LIBFT/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(AR) $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) $(MANDATORY) $(SERVER_MANDATORY) $(AR) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) $(CLIENT_MANDATORY) $(AR) -o $(CLIENT)

$(AR):
	make -C $(LIBFT_DIR)

bonus: $(AR) $(BONUS)
	$(CC) $(CFLAGS) $(BONUS) $(SERVER_BONUS) $(AR) -o $(SERVER)
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(AR) -o $(CLIENT)

debug: $(AR) $(DEBUG)
	$(CC) $(CFLAGS) $(DEBUG) $(SERVER_DEBUG) $(AR) -o $(SERVER)
	$(CC) $(CFLAGS) $(CLIENT_DEBUG) $(AR) -o $(CLIENT)

run: all
	./$(SERVER) 
#	./$(SERVER) & ./$(CLIENT) $$!

bonusrun: bonus
	./$(SERVER)

debugrun: debug
	./$(SERVER)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonusrun debugrun bonus debug