# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:03:36 by vsyutkin          #+#    #+#              #
#    Updated: 2024/05/23 22:15:40 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############################################################################ #
#						# PROJECT DIRECTORY DECLARATIONS #					   #
# ############################################################################ #

# ############################################################################ #
#						# PROJECT SOURCES DECLARATIONS #					   #
# ############################################################################ #

# ############################################################################ #
#						# PROJECT PATH DECLARATIONS #						   #
# ############################################################################ #

# ############################################################################ #
#						# PROJECT FILES DECLARATIONS #						   #
# ############################################################################ #

# ############################################################################ #
#						# PROJECT END_FILES DECLARATIONS #					   #
# ############################################################################ #

NAME = no_name_yet.you_suck
PROGRAM = ./$(NAME)

AR = ./0_LIBFT/libft.a

# ############################################################################ #
#						# PROJECT MACROS #									   #
# ############################################################################ #

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

CC = cc

RM = rm -f

ARMAKE = make -C $(LIBFT_DIR)

# ############################################################################ #
#						# PROJECT RULES DECLARATIONS #						   #
# ############################################################################ #

# all: $(NAME) 
all: help

$(NAME): $(AR)
	$(CC) $(CFLAGS) $(FILES) $(AR) -o $(NAME)

$(AR):
	make -C $(LIBFT_DIR)

clean: clear
	# $(ARMAKE) clean

fclean: clear clean
	# $(RM) $(NAME)
	# $(RM) a.out
	# $(ARMAKE) fclean

re: clear fclean all

# ############################################################################ #
#						# PROJECT BONUS #									   #

bonus: clear
	@echo "No bonus for this project done yet."

# ############################################################################ #
#						# PROJECT CUSTOM #									   #

clear:
	clear

# ############################################################################ #
#						# PROJECT TESTS #									   #

# ############################################################################ #
#										 # VERSIONS UPDATER AND GIT MANAGEMENT #
# ############################################################################ #

VERSIONS_DIR = ./release_notes/

# Variables
VERSIONS_NUMBER := $(shell cat $(VERSIONS_DIR)versions.txt)
COMMIT_FILE = $(VERSIONS_DIR)commits.txt
COMMIT_ARGS = $(shell cat $(VERSIONS_DIR)last_commit.txt)
EXIT_NORMINETTE := $(shell norminette > /dev/null; echo $$?)

# Make commands in this makefile
help: info
	@echo "Available commands: (make <command>)\n"
	@echo "help\n Display this help message.\n\n"
	@echo "checks\n Check for release notes directory and files.\n\
	If there is something missing, it will create it with defautl values.\n\n"
	@echo "git_cursus\n Use only from _CURSUS directory; \
	will push all projects to personal GitHub.\n\n"
	@echo "git_fpush\n Use only from project directory; \
	will push the project to git repo without norminette check.\n\n"
	@echo "git_push\n Use only from project directory; \
	if norminette's OK -> will push the project to git repo \
	(be it personal git OR vogsphere).\n\n"
	@echo "git_status\n Display git status.\n\n"
	@echo "norminette\n Check norminette.\n\n"

git: help

git_cursus: clear commit git_add git_status git_commit git_gitpush

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

git_norminette:
	@echo "Checking norminette..."
ifeq ($(EXIT_NORMINETTE), 0)
	make git_auto
else
	@echo "Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE.\n\
	Here's what you have to fix:"
	norminette | grep -v 'OK' 
endif

# git_norminette:
# 	@echo "Checking norminette..."
# ifeq ($(EXIT_NORMINETTE), 0)
# 	@echo "Norminette OK!"
# else
# 	@echo "Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE.\n\
# 	Here's what you have to fix:"
# 	norminette | grep -v 'OK' 
# endif

# DO NOT USE
git_auto:	fclean commit git_add git_status git_commit git_gitpush

git_msg1:
	@echo "\n\tPushing without norminette...\n"

git_msg2:
	@echo "Pushing to _CURSUS (the personal github)..."

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