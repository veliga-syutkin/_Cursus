# ############################################################################ #
#						# DIRECTORY DECLARATIONS #							   #
# ############################################################################ #

LIBFT_DIR = ./0_LIBFT/ 
OPERANDS_DIR = ./1_operands/
PROTECTIONS_DIR = ./2_protections/
PUSHSWAP_DIR = ./3_pushswap/
OPTIMIZATION_DIR = ./4_optimization/

# ############################################################################ #
#							# SOURCES DECLARATIONS #						   #
# ############################################################################ #

OPERANDS_FILES =	push.c \
					swap.c \
					rotate.c \
					reverse.c \
					string.c

PROTECTIONS_FILES =	check.c \
					dquote.c \
					error.c \

PUSHSWAP_FILES =	cost.c \
					ft_last_moves.c \
					instructions.c \
					list_utils.c \
					list.c \
					moves.c \
					pushswap.c \
					setup_utils.c \
					setup.c \
					solve_0.c \
					solve_three.c \
					sorted.c \
					weight.c \

OPTIMIZATION_FILES =	observer.c \

# ############################################################################ #
#							# PATH DECLARATIONS #							   #
# ############################################################################ #

OPERANDS_MANDATORY = $(addprefix $(OPERANDS_DIR), $(OPERANDS_FILES))
PROTECTIONS_MANDATORY = $(addprefix $(PROTECTIONS_DIR), $(PROTECTIONS_FILES))
PUSHSWAP_MANDATORY = $(addprefix $(PUSHSWAP_DIR), $(PUSHSWAP_FILES))
OPTIMIZATION_MANDATORY = $(addprefix $(OPTIMIZATION_DIR), $(OPTIMIZATION_FILES))

# ############################################################################ #
#							# FILES DECLARATIONS #							   #
# ############################################################################ #

FILES = $(OPERANDS_MANDATORY) $(PROTECTIONS_MANDATORY) $(PUSHSWAP_MANDATORY) $(OPTIMIZATION_MANDATORY)

# ############################################################################ #
#						# END_FILES DECLARATIONS #							   #
# ############################################################################ #

NAME = push_swap
PROGRAM = ./$(NAME)

AR = ./0_LIBFT/libft.a

# ############################################################################ #
#								# MACROS #									   #
# ############################################################################ #

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

CC = cc

RM = rm -f

ARMAKE = make -C $(LIBFT_DIR)

#100 = 89 24 40 68 58 91 16 77 25 98 65 34 15 67 72 70 11 93 47 39 31 12 41 62 45 37 2 61 6 9 64 3 8 42 27 100 28 46 50 51 80 7 14 35 63 19 60 5 4 13 55 10 54 84 21 56 95 32 20 90 79 69 52 73 97 33 66 23 1 57 81 87 82 92 18 48 30 88 59 17 74 36 85 26 49 29 78 96 22 75 94 71 86 38 76 99 53 83 44 43 
100 = 81 74 97 89 47 3 13 35 76 33 5 79 25 94 92 26 57 85 14 45 12 36 78 39 90 6 24 73 82 23 56 95 31 99 7 50 62 10 70 29 51 21 20 86 48 54 11 63 17 67 43 22 30 41 49 42 8 38 19 16 65 77 18 80 27 93 84 96 75 69 68 34 37 64 66 61 44 53 71 4 52 91 1 32 2 55 98 15 60 100 9 46 58 59 72 28 87 83 88 40 
#100 = 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

500 = 130 449 391 10 140 33 251 374 63 343 273 40 316 65 407 460 64 133 179 3 461 323 493 198 446 474 20 330 105 418 69 178 242 284 280 32 344 465 265 38 385 7 146 468 400 210 41 408 121 285 200 53 62 290 72 215 327 11 157 473 2 23 15 450 182 241 263 209 466 24 426 336 340 282 52 26 66 346 380 286 281 135 376 95 447 410 218 75 164 451 405 36 98 401 422 206 333 325 49 338 409 237 188 134 272 389 151 67 230 43 435 261 124 302 9 129 94 109 232 394 51 255 359 220 97 453 122 329 19 297 463 74 278 494 310 490 279 110 404 70 252 180 195 299 189 207 484 173 402 364 205 79 93 29 262 488 183 34 113 256 214 27 127 149 184 353 145 416 82 89 58 235 257 399 485 500 419 319 238 233 166 42 414 191 314 341 161 8 332 366 159 212 300 365 479 225 475 427 119 331 360 441 334 370 162 144 171 398 305 57 335 190 153 266 249 250 357 382 354 458 393 428 37 71 77 411 47 328 4 459 477 193 383 438 25 315 439 303 317 492 21 432 236 174 106 392 433 222 138 342 313 311 467 104 90 379 483 362 348 403 117 13 158 169 115 470 219 107 91 349 489 480 326 307 271 111 50 112 92 254 228 84 413 309 368 73 388 318 423 294 22 123 259 358 223 355 386 293 397 35 395 12 406 54 108 76 181 476 455 229 296 86 137 116 234 1 224 172 436 387 499 61 339 367 175 5 96 430 31 14 143 83 445 378 287 152 55 132 283 6 260 60 177 448 347 361 356 486 306 396 442 136 491 28 295 88 264 168 231 269 81 147 45 454 18 440 101 478 415 487 352 267 208 240 373 114 301 216 194 497 363 187 274 384 56 16 258 372 211 495 288 221 48 276 321 444 471 431 139 322 412 243 170 192 167 201 217 462 87 245 78 125 239 248 85 371 156 202 17 472 186 456 312 102 185 155 277 59 390 437 429 375 30 420 369 128 498 308 421 126 204 291 196 150 246 213 244 424 351 345 464 452 197 163 298 350 253 160 324 481 80 68 203 289 165 434 337 270 457 46 417 176 292 443 99 226 482 154 425 275 247 39 142 227 268 320 120 103 469 131 381 148 377 44 496 141 304 118 199 100

# ############################################################################ #
#							# RULES DECLARATIONS #							   #
# ############################################################################ #

all: $(NAME) 

$(NAME): $(AR)
	$(CC) $(CFLAGS) $(FILES) $(AR) -o $(NAME)

$(AR):
	make -C $(LIBFT_DIR)

# ############################################################################ #
#								# BONUS #									   #

bonus: 
	@echo "No bonus for this project done yet."

# ############################################################################ #
#								# CUSTOM #									   #

debug:
	lldb $(NAME) $(100)

valgrind:
	valgrind --leak-check=full ./$(NAME) $(100)

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
	./$(NAME) 2 1 3 5 4

5special: all
	./$(NAME) 1 5 2 4 3

100: all
	./$(NAME) $(100)
# ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; ./$(NAME) $${ARG}

500: all
	./$(NAME) $(500)
# ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./$(NAME) $${ARG}

echo:
	@echo "\t100:" $(100)
	@echo "\t500:" $(500)

# ############################################################################ #

clean:
	$(ARMAKE) clean

fclean: clean
	$(RM) $(NAME)
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