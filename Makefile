NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS_DBG	= -Wall -Wextra -g3 -fsanitize=address,undefined

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJ_DIR		= obj
SRCS		= push_swap.c input.c misc.c stack.c sorting_alg.c alloc.c sv.c \
			  algorithms/turk/turk.c algorithms/turk/helpers.c \
			  algorithms/turk/turk_utils.c algorithms/turk/turk_target.c \
			  algorithms/turk/turk_ops.c
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# --- benchmark config (node bench.js) ---
BENCH_RUNS	?= 20
BENCH_SIZES	?= 5,100,500
BENCH_SCRIPT	= bench.js
NODE		?= node

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

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

# --- benchmarking ---
# Usage:
#   make bench                            (default: 20 runs, sizes 5,100,500)
#   make bench BENCH_RUNS=50 BENCH_SIZES=100,500
#   make bench-save                       save results to bench_baseline.json
#   make bench-compare                    compare against bench_baseline.json
#   make bench-json                       raw JSON output
bench: $(NAME)
	@command -v $(NODE) >/dev/null 2>&1 || { echo "node not found"; exit 1; }
	$(NODE) $(BENCH_SCRIPT) -b ./$(NAME) -r $(BENCH_RUNS) -s $(BENCH_SIZES)

bench-save: $(NAME)
	@command -v $(NODE) >/dev/null 2>&1 || { echo "node not found"; exit 1; }
	$(NODE) $(BENCH_SCRIPT) -b ./$(NAME) -r $(BENCH_RUNS) -s $(BENCH_SIZES) --save bench_baseline.json

bench-compare: $(NAME)
	@command -v $(NODE) >/dev/null 2>&1 || { echo "node not found"; exit 1; }
	$(NODE) $(BENCH_SCRIPT) -b ./$(NAME) -r $(BENCH_RUNS) -s $(BENCH_SIZES) --compare bench_baseline.json

bench-json: $(NAME)
	@command -v $(NODE) >/dev/null 2>&1 || { echo "node not found"; exit 1; }
	$(NODE) $(BENCH_SCRIPT) -b ./$(NAME) -r $(BENCH_RUNS) -s $(BENCH_SIZES) --json

.PHONY: all debug clean fclean re bench bench-save bench-compare bench-json
