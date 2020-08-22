PUSH_SWAP = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I inc -I libft
LIBFT = libft/libft.a
SRC_DIR = src
PS_SRC = \
		push_swap\
		get_median_in_a\
		get_median_in_array\
		pa_elms_gtet_median\
		pa_elms_gtet_median_part2\
		perform_op_ntimes\
		print_op_list\
		quicksort\
		sort\
		sort_3\
		sort_5\
		sort_helpers\
		sort_remaining_unsorteds_in_a\
		sort_top_3
SHARED_SRC =\
		error\
		free\
		list_manipulation\
		load\
		operations\
		ps_atoi\
		validation
CHECKER_SRC =\
		checker
OBJ_DIR = $(SRC_DIR)/obj
SHARED_OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SHARED_SRC))
PS_OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(PS_SRC))
CHECKER_OBJ = $(patsubst %, $(OBJ_DIR)/checker_obj/%.o, $(CHECKER_SRC))

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(LIBFT) $(SHARED_OBJ) $(PS_OBJ)
	@echo "building $@..."
	@$(CC) $(CFLAGS) $(LIBFT) $(SHARED_OBJ) $(PS_OBJ) -o $@
	@echo "$@ is built."

$(CHECKER): $(LIBFT) $(SHARED_OBJ) $(CHECKER_OBJ)
	@echo "building $@..."
	@$(CC) $(CFLAGS) $(LIBFT) $(SHARED_OBJ) $(CHECKER_OBJ) -o $@
	@echo "$@ is built."

$(LIBFT):
	@echo "building $@..."
	make -C libft
	@echo "$@ is built."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo " > Compiling $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/checker_obj/%.o: $(SRC_DIR)/checker/%.c
	@mkdir -p $(OBJ_DIR)/checker_obj
	@echo " > Compiling $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C libft clean
	@rm -rf $(OBJ_DIR)
	@echo "deleted object files"

fclean: clean
	make -C libft fclean
	@rm -f $(PUSH_SWAP)
	@echo "deleted $(PUSH_SWAP)"
	@rm -f $(CHECKER)
	@echo "deleted $(CHECKER_SRC)"

re: fclean all