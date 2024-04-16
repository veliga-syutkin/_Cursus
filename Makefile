# ############################################################################ #
#					# VERSIONS UPDATER AND GIT MANAGEMENT #					   #
# ############################################################################ #

VERSIONS_DIR = ./release_notes/

# variable
VERSIONS_NUMBER := $(shell cat $(VERSIONS_DIR)versions.txt)

COMMIT_FILE = $(VERSIONS_DIR)commits.txt

COMMIT_ARGS := $(ARGS)

ARGUMENT ?= something

EXIT_NORMINETTE := $(shell norminette > /dev/null; echo $$?)

all: info

git_cursus: commit git_add git_commit git_gitpush

git_push: norminette git_auto

ask:
	@read -p "Please specify the commit message: " user_input; \
	export ARGUMENT=$$user_input; \

info:
	@echo "This makefile is only for managing git!"
	@echo "In _CURSUS/ directory, please use 'make git_cursus'"
	@echo "In projects directory, please use 'make git_push'"

# Release directory and files checker
ifeq ($(shell cd $(VERSIONS_DIR) && ls),)
	@echo "Creating release notes directory..."
	@mkdir $(VERSIONS_DIR)
	@echo "Done!"
endif

ifeq ($(shell cat $(VERSIONS_DIR)versions.txt),)
	@echo "Creating versions file..."
	@echo "0" > $(VERSIONS_DIR)versions.txt
	@echo "Done!"
endif

ifeq ($(shell cat $(VERSIONS_DIR)commits.txt),)
	@echo "Creating commits file..."
	@echo "\t\t\t$(NAME) release notes:" > $(VERSIONS_DIR)commits.txt
	@echo "Done!"
endif
#	* *	*

version_update:
	@echo "Current version: $(VERSIONS_NUMBER)"
	@echo "Incrementing version"
	@echo $$(($(VERSIONS_NUMBER) + 1)) > $(VERSIONS_DIR)versions.txt
	@echo "New version: $$(($(VERSIONS_NUMBER) + 1))"
	@echo "Creating new release note"

git:
	@echo "norminette"
	@echo "git_norminette"
	@echo "git_auto"
	@echo "git_push"
	@echo "git_fpush"
	@echo "git_status"
	@echo "git_cursus"

norminette:
	@echo "Checking norminette..."
ifeq ($(EXIT_NORMINETTE), 0)
	@echo "Norminette passed!"
else
	@echo "Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE."
	norminette | grep -v 'OK' 
endif

git_norminette:
	norminette

# DO NOT USE THIS UNLESS YOU'RE SURE
git_auto:	fclean commit git_add git_commit git_gitpush

git_msg1:
	@echo "\n\tPushing without norminette...\n"

git_msg2:
	@echo "Pushing to _CURSUS (the personal private github)..."

git_fpush: git_msg1 git_auto
	
git_status:
	git status

commit: ask version_update
	@echo "v$$(($(VERSIONS_NUMBER) + 1))\n$(COMMIT_ARGS)\n" >> $(COMMIT_FILE)

# ############################################################################ #
#					# BASIC GIT COMMANDS #									   #

git_add:
	git add *

git_commit:
	git commit -m "v$$(($(VERSIONS_NUMBER) + 1)) $(COMMIT_ARGS)"

git_gitpush:
	git push
#																			   #
# ############################################################################ #