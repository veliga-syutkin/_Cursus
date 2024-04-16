# ############################################################################ #
#					# VERSIONS UPDATER AND GIT MANAGEMENT #					   #
# ############################################################################ #

VERSIONS_DIR = ./release_notes/

# variable
VERSIONS_NUMBER := $(shell cat $(VERSIONS_DIR)versions.txt)

COMMIT_FILE = $(VERSIONS_DIR)commits.txt

COMMIT_ARGS := $(ARGS)

EXIT_NORMINETTE := $(shell norminette > /dev/null; echo $$?)

all: norminette


# Release directory and files checker
ifeq ($(shell cd $(VERSIONS_DIR) && ls),)
	@echo "Creating release notes directory"
	@mkdir $(VERSIONS_DIR)
endif

ifeq ($(shell cat $(VERSIONS_DIR)versions.txt),)
	@echo "Creating versions file"
	@echo "0" > $(VERSIONS_DIR)versions.txt
endif

ifeq ($(shell cat $(VERSIONS_DIR)commits.txt),)
	@echo "Creating commits file"
	@echo "\t\t\t$(NAME) release notes:" > $(VERSIONS_DIR)commits.txt
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
	@echo "norminette exit code: $(EXIT_NORMINETTE)"
ifeq ($(EXIT_NORMINETTE), 0)
	@echo "Norminette passed!"
else
	@echo "Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE."
endif

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

git_msg1:
	@echo "\n\tPushing without norminette...\n"

git_fpush: git_msg1 git_auto
	
git_status:
	git status

git_cursus:
	@echo "Pushing to _CURSUS (the personal private github)..."
	git add ../*
	git status
	git commit -m "😏👌 Updated via Makefile(tm) 😏👌"
	git push
	@echo "\n\tFor detailing commit, please do git pushing manually. Thank you."

commit: version_update
	@echo "v$$(($(VERSIONS_NUMBER) + 1))\n$(COMMIT_ARGS) \n" >> $(COMMIT_FILE)
