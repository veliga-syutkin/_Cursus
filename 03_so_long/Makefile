# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:03:36 by vsyutkin          #+#    #+#              #
#    Updated: 2024/05/23 18:15:40 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############################################################################ #
#						# PROJECT SOURCES DECLARATIONS #					   #
# ############################################################################ #

#Only .c files
MAIN = so_long.c
KEYS = esc.c
MAPS = maps.c \
		check_map.c \
		map_grid.c
ERRORS = errors.c
MHANDLER = mhandler.c \
			mhandler_utils.c

# ############################################################################ #
#						# PROJECT PATH DECLARATIONS #						   #
# ############################################################################ #

#Only directories
LIBFT_DIR = ./0_LIBFT/
MLX_DIR = ./1_MLX42/
KEY_DIR = ./2_KEY/
MAP_DIR = ./3_MAPS/
ERR_DIR = ./4_ERRORS/
MHANDLER_DIR = ./9_MHANDLER/

PROJECT_DIR = $(LIBFT_DIR) $(KEY_DIR) $(MAP_DIR) $(ERR_DIR) $(MHANDLER_DIR)

# ############################################################################ #
#						# PROJECT FILES DECLARATIONS #						   #
# ############################################################################ #

#Gathers all files in $(FILES)
FILES = $(MAIN) \
		$(addprefix $(KEY_DIR), $(KEYS)) \
		$(addprefix $(MAP_DIR), $(MAPS)) \
		$(addprefix $(ERR_DIR), $(ERRORS)) \
		$(addprefix $(MHANDLER_DIR), $(MHANDLER))

INCLUDES = -I $(MLX_DIR)include/MLX42/MLX42.h

# Library files
AR = ./0_LIBFT/libft.a
MLX42 = ./1_MLX42/build/libmlx42.a

# ############################################################################ #
#						# PROJECT END_FILES DECLARATIONS #					   #
# ############################################################################ #

NAME = so_long

PROGRAM = ./$(NAME)

LIBS = $(AR) $(MLX42)

# ############################################################################ #
#						# PROJECT MACROS #									   #
# ############################################################################ #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

RM = rm -f

ARMAKE = make -C $(LIBFT_DIR)
MLX42MAKE = make -C $(MLX_DIR)

# ############################################################################ #
#						# PROJECT RULES DECLARATIONS #						   #
# ############################################################################ #

MLX42_FLAG = -Iinclude -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(LIBS)
	$(CC) $(CFLAGS) $(FILES) $(LIBS) $(MLX42_FLAG) -o $(NAME)

$(LIBS):
	$(ARMAKE)
	$(MLX42MAKE)

clean: clear
	$(ARMAKE) clean
	$(MLX42MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out
	$(ARMAKE) fclean
	$(MLX42MAKE) fclean

re: clear fclean all

# ############################################################################ #
#						# PROJECT BONUS #									   #

bonus: clear
	@echo "No bonus for this project done yet."

# ############################################################################ #
#						# PROJECT CUSTOM #									   #

clear:
	clear

run: clear
	./$(NAME)

valgrind: clear
	valgrind --leak-check=full ./$(NAME)

# ############################################################################ #
#						# PROJECT TESTS #									   #

test: clear

# ############################################################################ #
#										 # VERSIONS UPDATER AND GIT MANAGEMENT #
# ############################################################################ #

# Colors
NC = \033[0m
BOLD_BLACK = \033[1;30m
RED = \033[0;31m
BOLD_RED = \033[1;31m
GREEN = \033[0;32m
BOLD_GREEN = \033[1;32m
YELLOW = \033[0;33m
BOLD_YELLOW = \033[1;33m
BLUE = \033[0;34m
BOLD_BLUE = \033[1;34m
BOLD_PURPLE = \033[1;35m
PURPLE = \033[0;35m
BOLD_CYAN = \033[1;36m
CYAN = \033[0;36m
BOLD_WHITE = \033[1;37m
WHITE = \033[0;37m
BACKGROUND_GREEN = \033[42m
BACKGROUND_RED = \033[41m
BACKGROUND_WHITE = \033[47m

VERSIONS_DIR = ./release_notes/

# Variables
NORMINETTE_DIR = so_long.h $(MAIN) $(PROJECT_DIR)
VERSIONS_NUMBER := $(shell cat $(VERSIONS_DIR)versions.txt)
COMMIT_FILE = $(VERSIONS_DIR)commits.txt
COMMIT_ARGS = $(shell cat $(VERSIONS_DIR)last_commit.txt)
EXIT_NORMINETTE := $(shell norminette $(NORMINETTE_DIR) > /dev/null; echo $$?)

# Make commands in this makefile
help: info
	@echo "Available commands: (make <command>)\n"
	@echo "help\n Display this help message.\n\n"
	@echo "norminette, git_norminette\n Check norminette.\n\n"
	@echo "git_cursus\n Use only from _CURSUS directory; \
	will push all projects to personal GitHub.\n\n"
	@echo "git_push\n Use only from project directory; \
	if norminette's OK -> will push the project to git repo \
	(be it personal git OR vogsphere).\n\n"
	@echo "git_fpush\n Use only from project directory; \
	will push the project to git repo without norminette check.\n\n"
	@echo "git_status\n Display git status.\n\n"

git: help

git_cursus: clear commit git_add git_commit git_gitpush

git_push: clear git_norminette

git_fpush: clear git_msg1 git_auto
#	* *	*

# Release directory and files checker
checks:
	@echo "Checking for release notes directory..."
	@echo "Checking for versions file..."
	@echo "Checking for commits file..."
	@echo "Checking for last commit file..."
ifeq ($(wildcard $(VERSIONS_DIR)),)
	@echo "Creating release notes directory..."
	@mkdir $(VERSIONS_DIR)
	@echo "Done!"
endif

ifeq ($(wildcard $(VERSIONS_DIR)versions.txt),)
	@echo "Creating versions file..."
	@echo "0" > $(VERSIONS_DIR)versions.txt
	@echo "Done!"
endif

ifeq ($(wildcard $(VERSIONS_DIR)commits.txt),)
	@echo "Creating commits file..."
	@echo "\t\t\t$(NAME) release notes:" > $(VERSIONS_DIR)commits.txt
	@echo "Done!"
endif

ifeq ($(wildcard $(VERSIONS_DIR)last_commit.txt),)
	@echo "Creating last commit file..."
	@echo "0" > $(VERSIONS_DIR)last_commit.txt
	@echo "Done!\t"
endif
#	* *	*

# utils:
ask:
	@echo "Please enter your commit message:"
	@read COMMIT_ARGS; \
	echo $$COMMIT_ARGS > $(VERSIONS_DIR)last_commit.txt

info:
	@echo "This makefile is only for managing git!"
	@echo "In _CURSUS/ directory, please use 'make git_cursus'"
	@echo "In projects directory, please use 'make git_push'"

commit: checks ask version_update
	@echo "v$$(($(VERSIONS_NUMBER) + 1))\n$(COMMIT_ARGS)\n" >> $(COMMIT_FILE)

version_update:
	@echo "Current version: $(VERSIONS_NUMBER)"
	@echo "Incrementing version"
	@echo $$(($(VERSIONS_NUMBER) + 1)) > $(VERSIONS_DIR)versions.txt
	@echo "New version: $$(($(VERSIONS_NUMBER) + 1))"
	@echo "Creating new release note"

norminette: norminette_msg
ifeq ($(EXIT_NORMINETTE), 0)
	@echo "$(BOLD_GREEN)Norminette OK!$(NC)"
else
	@echo "$(BOLD_RED)Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE.\n\
	Here's what you have to fix:$(NC)"
	norminette $(NORMINETTE_DIR) | grep -v 'OK' 
endif

# DO NOT USE
git_norminette: norminette_msg
ifeq ($(EXIT_NORMINETTE), 0)
	make git_auto
else
	@echo "$(BOLD_RED)Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE.\n\
	Here's what you have to fix:$(NC)"
	norminette $(NORMINETTE_DIR) | grep -v 'OK' 
endif

git_auto:	fclean commit git_add git_commit git_gitpush

git_msg1:
	@echo "\n\tPushing without norminette...\n"

git_msg2:
	@echo "Pushing to _CURSUS (the personal github)..."

norminette_msg:
	@echo "$(YELLOW)Checking norminette in $(NORMINETTE_DIR)...$(NC)"

# ############################################################################ #
#														  # BASIC GIT COMMANDS #
git_status:
	git status

git_add:
	git add *

git_commit:
	git commit -m "v$$(($(VERSIONS_NUMBER) + 1)) $(COMMIT_ARGS)"

git_gitpush:
	git push
#																			   #
# ############################################################################ #

# ############################################################################ #
#								# PHONY #									   #
# ############################################################################ #

.PHONY: all clean fclean re bonus clear help git git_cursus git_push git_fpush \
git_status git_add git_commit git_gitpush norminette git_norminette git_auto \
git_msg1 git_msg2
# .PHONY is used to declare phony targets. When a target is phony, it will
# run the target rather do something to a file. 
# 	Check "Makefile Implicit Rules - Phony" for more info.