# ############################################################################ #
#							# SOURCES DECLARATIONS #						   #
# ############################################################################ #

SERVER_FILES = 	server_sigaction.c \
				server_utils.c

CLIENT_FILES =	client_sigaction.c \
				client_utils.c

SERVER_BONUS_FILES =	server_sigaction.c \
						server_utils.c

CLIENT_BONUS_FILES = 	client_receptive.c \
						client_utils.c

SERVER_DEBUG_FILES = server_sigaction.c
CLIENT_DEBUG_FILES = client_sigaction.c

SERVER_CRIMINAL_FILES =	server_sigaction.c \
						server_utils.c

CLIENT_CRIMINAL_FILES =	client_receptive.c \
						client_utils.c

# ############################################################################ #
#							# PATH DECLARATIONS #							   #
# ############################################################################ #

SERVER_MANDATORY = $(addprefix $(MANDATORY_DIR), $(SERVER_FILES))
CLIENT_MANDATORY = $(addprefix $(MANDATORY_DIR), $(CLIENT_FILES))

SERVER_BONUS = $(addprefix $(BONUS_DIR), $(SERVER_BONUS_FILES))
CLIENT_BONUS = $(addprefix $(BONUS_DIR), $(CLIENT_BONUS_FILES))

SERVER_DEBUG = $(addprefix $(DEBUG_DIR), $(SERVER_DEBUG_FILES))
CLIENT_DEBUG = $(addprefix $(DEBUG_DIR), $(CLIENT_DEBUG_FILES))

SERVER_CRIMINAL = $(addprefix $(CRIMINAL_DIR), $(SERVER_CRIMINAL_FILES))
CLIENT_CRIMINAL = $(addprefix $(CRIMINAL_DIR), $(CLIENT_CRIMINAL_FILES))

# ############################################################################ #
#						# DIRECTORY DECLARATIONS #							   #
# ############################################################################ #

LIBFT_DIR = ./0_LIBFT/ 
MANDATORY_DIR = ./1_minitalk_mandatory/
BONUS_DIR = ./2_minitalk_bonus/
DEBUG_DIR = ./3_minitalk_bonus_debug/
CRIMINAL_DIR = ./9_minitalk_criminal/

# ############################################################################ #
#						# END_FILES DECLARATIONS #							   #
# ############################################################################ #

NAME = minitalk
SERVERMANDATORY = server
CLIENTMANDATORY = client

NAME_BONUS = minitalk_bonus
SERVERBONUS = server_bonus
CLIENTBONUS = client_bonus

NAME_DEBUG = minitalk_bonus_debug
SERVERDEBUG = server_debug
CLIENTDEBUG = client_debug

NAME_CRIMINAL = minitalk_criminal
SERVERCRIMINAL = server_criminal
CLIENTCRIMINAL = client_criminal

NAMES =	$(SERVERMANDATORY) $(CLIENTMANDATORY) \
		$(SERVERBONUS) $(CLIENTBONUS) \
		$(SERVERDEBUG) $(CLIENTDEBUG) \
		$(SERVERCRIMINAL) $(CLIENTCRIMINAL)

AR = ./0_LIBFT/libft.a

# ############################################################################ #
#								# MACROS #									   #
# ############################################################################ #

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -f

ARMAKE = make -C $(LIBFT_DIR)

# ############################################################################ #
#							# RULES DECLARATIONS #							   #
# ############################################################################ #

all: $(NAME)

$(NAME): $(AR) $(SERVERMANDATORY) $(CLIENTMANDATORY)

$(SERVERMANDATORY):
	$(CC) $(CFLAGS) $(SERVER_MANDATORY) $(AR) -o $(SERVERMANDATORY)

$(CLIENTMANDATORY):
	$(CC) $(CFLAGS) $(CLIENT_MANDATORY) $(AR) -o $(CLIENTMANDATORY)

$(AR):
	make -C $(LIBFT_DIR)

# ############################################################################ #
#								# BONUS #									   #

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(AR) $(SERVERBONUS) $(CLIENTBONUS)

$(SERVERBONUS):
	$(CC) $(CFLAGS) $(SERVER_BONUS) $(AR) -o $(SERVERBONUS)

$(CLIENTBONUS):
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(AR) -o $(CLIENTBONUS)

# ############################################################################ #
#								# DEBUG #									   #

debug: $(NAME_DEBUG)

$(NAME_DEBUG): $(AR) $(SERVERDEBUG) $(CLIENTDEBUG)

$(SERVERDEBUG):
	$(CC) $(CFLAGS) $(SERVER_DEBUG) $(AR) -o $(SERVERDEBUG)

$(CLIENTDEBUG):
	$(CC) $(CFLAGS) $(CLIENT_DEBUG) $(AR) -o $(CLIENTDEBUG)

# ############################################################################ #
#								# CRIMINAL #									   #

criminal: $(NAME_CRIMINAL)

$(NAME_CRIMINAL): $(AR) $(SERVERCRIMINAL) $(CLIENTCRIMINAL)

$(SERVERCRIMINAL):
	$(CC) $(CFLAGS) $(SERVER_CRIMINAL) $(AR) -o $(SERVERCRIMINAL)

$(CLIENTCRIMINAL):
	$(CC) $(CFLAGS) $(CLIENT_CRIMINAL) $(AR) -o $(CLIENTCRIMINAL)

# ############################################################################ #

clean:
	$(ARMAKE) clean

fclean: clean
	$(RM) $(NAMES)
	$(ARMAKE) fclean

re: fclean all

# ############################################################################ #

combo: all bonus debug

.PHONY: all clean fclean re bonus debug combo