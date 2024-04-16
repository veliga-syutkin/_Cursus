# ############################################################################ #
#					# VERSIONS UPDATER AND GIT MANAGEMENT #					   #
# ############################################################################ #

VERSIONS_DIR = ./release_notes/


# variable
VERSIONS_NUMBER := $(shell cat $(VERSIONS_DIR)versions.txt)

COMMIT_FILE = $(VERSIONS_DIR)commits.txt

COMMIT_ARGS = $(shell cat $(VERSIONS_DIR)last_commit.txt)

ARGUMENT ?= something

EXIT_NORMINETTE := $(shell norminette > /dev/null; echo $$?)

all: checks info

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

git_cursus: commit git_add git_commit git_gitpush

git_push: norminette git_auto

ask:
	@echo "Please enter your commit message:"
	@read COMMIT_ARGS; \
	echo $$COMMIT_ARGS > $(VERSIONS_DIR)last_commit.txt

info:
	@echo "This makefile is only for managing git!"
	@echo "In _CURSUS/ directory, please use 'make git_cursus'"
	@echo "In projects directory, please use 'make git_push'"


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