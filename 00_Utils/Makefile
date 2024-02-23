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

# ############################################################################ #
#							# PATH DECLARATIONS #							   #
# ############################################################################ #

SERVER_MANDATORY = $(addprefix $(MANDATORY_DIR), $(SERVER_FILES))
CLIENT_MANDATORY = $(addprefix $(MANDATORY_DIR), $(CLIENT_FILES))

SERVER_BONUS = $(addprefix $(BONUS_DIR), $(SERVER_BONUS_FILES))
CLIENT_BONUS = $(addprefix $(BONUS_DIR), $(CLIENT_BONUS_FILES))

SERVER_DEBUG = $(addprefix $(DEBUG_DIR), $(SERVER_DEBUG_FILES))
CLIENT_DEBUG = $(addprefix $(DEBUG_DIR), $(CLIENT_DEBUG_FILES))

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

NAMES =	$(SERVERMANDATORY) $(CLIENTMANDATORY) \
		$(SERVERBONUS) $(CLIENTBONUS) \
		$(SERVERDEBUG) $(CLIENTDEBUG) \

AR = ./0_LIBFT/libft.a

# ############################################################################ #
#								# MACROS #									   #
# ############################################################################ #

CFLAGS = -Wall -Wextra -Werror -g3

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
#								# CUSTOM #									   #

combo: all bonus debug

# ############################################################################ #

clean:
	$(ARMAKE) clean

fclean: clean
	$(RM) $(NAMES)
	$(ARMAKE) fclean

re: fclean all

# ############################################################################ #
#							# SUBMITTING #									   #
# ############################################################################ #

git:
	@echo "norminette"
	@echo "git_norminette"
	@echo "git_auto"
	@echo "git_push"
	@echo "git_fpush"
	@echo "git_status"
	@echo "git_cursus"

norminette:
	norminette

git_norminette:
	norminette

# DO NOT USE THIS UNLESS YOU'RE SURE
git_auto:	fclean
	git add *
	git commit -m "😏👌 Updated via Makefile(tm) 😏👌"
	git push

git_push:
	@echo Pushing if norminette OK...
	./norminette_before_push.sh

git_fpush:
	@echo Pushing without norminette...
	git_auto

git_status:
	git status

git_cursus:
	@echo "Pushing to _CURSUS (the personal private github)..."
	git add ../*
	git status
	git commit -m "😏👌 Updated via Makefile(tm) 😏👌"
	git push
	@echo "\n\tFor detailing commit, please do git pushing manually. Thank you."

# ############################################################################ #
#								# PHONY #									   #
# ############################################################################ #

.PHONY: all clean fclean re bonus debug combo norminette \
		git git_norminette git_auto git_push git_fpush git_status git_cursus
# .PHONY is used to declare phony targets. When a target is phony, it will
# run the target rather do something to a file. 
# 	Check "Makefile Implicit Rules - Phony" for more info.