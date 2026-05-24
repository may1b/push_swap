NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS_DBG	= -Wall -Wextra -g3 -fsanitize=address,undefined

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJ_DIR		= obj
SRCS	= push_swap.c push_swap_init.c sort_dispatch.c input.c input_args.c input_utils.c misc.c stack.c stack_ops.c \
		  stack_rotate.c stack_rotate2.c sv.c \
		  sort_utils.c rotate_cost.c algorithms/bubble/bubble.c \
		  bench.c algorithms/lis/lis_sort.c algorithms/lis/lis_helpers.c \
		  algorithms/small/small_sort.c \
		  algorithms/k/k_sort.c algorithms/k/k_helpers.c \
		  algorithms/radix/radix_sort.c
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c push_swap.h | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

debug: CFLAGS = $(CFLAGS_DBG)
debug: fclean $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
