# ############################################################################ #
#							# SOURCES DECLARATIONS #						   #
# ############################################################################ #

OPERANDS_FILES =	push.c \
					swap.c \
					rotate.c \
					reverse.c

PROTECTIONS_FILES =	check.c \
					dquote.c \
					error.c \

PUSHSWAP_FILES =	list.c \
					list_utils.c \
					pushswap.c \
					setup.c \
					setup_utils.c \
					solve_0.c \
					solve_three.c \
					sorted.c \

# ############################################################################ #
#							# PATH DECLARATIONS #							   #
# ############################################################################ #

OPERANDS_MANDATORY = $(addprefix $(OPERANDS_DIR), $(OPERANDS_FILES))
PROTECTIONS_MANDATORY = $(addprefix $(PROTECTIONS_DIR), $(PROTECTIONS_FILES))
PUSHSWAP_MANDATORY = $(addprefix $(PUSHSWAP_DIR), $(PUSHSWAP_FILES))

# ############################################################################ #
#						# DIRECTORY DECLARATIONS #							   #
# ############################################################################ #

LIBFT_DIR = ./0_LIBFT/
MLX_DIR = ./1_MLX42/

# ############################################################################ #
#						# END_FILES DECLARATIONS #							   #
# ############################################################################ #

NAME = so_long

AR = ./0_LIBFT/libft.a

MLX42 = ./1_MLX42/build/libmlx42.a

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

all: libmlx42 $(NAME)

libmlx42:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(AR) $(MLX42) $(PUSHSWAPMANDATORY)

$(PUSHSWAPMANDATORY):
	$(CC) $(CFLAGS) $(OPERANDS_MANDATORY) $(PROTECTIONS_MANDATORY) $(PUSHSWAP_MANDATORY) $(AR) -o $(NAME)

$(AR):
	make -C $(LIBFT_DIR)

# ############################################################################ #
#								# BONUS #									   #

bonus: 
	@echo "No bonus for this project done yet."

# ############################################################################ #
#								# CUSTOM #									   #

debug:
	lldb $(NAME)

string: all
	./$(NAME) string

strings: all
	./$(NAME) strings

3order: all
	./$(NAME) 0 1 2

3ordernot: all
	./$(NAME) 2 0 1

5order: all
	./$(NAME) 0 1 2 3 4

5ordernot: all
	./$(NAME) -101 42 -42 0 101

100: all
	./$(NAME) $(100)
# ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; ./$(NAME) $${ARG}

500: all
	./$(NAME) $(500)
# ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./$(NAME) $${ARG}

# ############################################################################ #

clean:
	$(ARMAKE) clean
	$(RM) $(MLX_DIR)build

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

# ############################################################################ #
#								# PHONY #									   #
# ############################################################################ #

.PHONY: all clean fclean re bonus debug combo norminette \
		git git_norminette git_auto git_push git_fpush git_status git_cursus
# .PHONY is used to declare phony targets. When a target is phony, it will
# run the target rather do something to a file. 
# 	Check "Makefile Implicit Rules - Phony" for more info.