NAME	:= push_swap

CC = cc
CFLAGS	:= -Wextra -Wall -Werror -g 

LIBFT	:= ./libs/libft

HEADERS	:=	-I ./inc \
			-I $(LIBFT)

LIBS	:=	$(LIBFT)/libft.a 

SRC :=	src/main.c \
		src/error.c \
		src/utils.c \
		src/check.c \
		src/save_args.c \
		src/algorithm.c \
		src/list.c \
		src/push.c \
		src/swap.c \
		src/rotate.c \
		src/rev_rotate.c \
		src/stack.c \
		src/more_utils.c \
		src/push_in.c \
		src/check_size.c \
		src/move.c

OBJ	= $(patsubst src%, obj%, $(SRC:.c=.o))

all: libft obj $(NAME)

libft:
	@make -C libs/libft all

$(NAME): $(OBJ)
	@echo "compiling ${NAME}"
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj/%.o: bonus/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj:
	@mkdir -p obj

clean:
	@rm -rf obj
	@make -C libs/libft clean

fclean: clean
	@make -C libs/libft fclean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, obj