# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 16:52:47 by toferrei          #+#    #+#              #
#    Updated: 2024/10/18 18:05:10 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT		=	Libft/
PRINTF		=	Ft_printf/
SRC			=	Sources/
OBJ_DIR		=	Objects/
LIBFT_A		=	$(LIBFT)libft.a
PRINTF_A	=	$(PRINTF)libftprintf.a
SOURCES		=	$(SRC)errors.c \
				$(SRC)ft_abs.c \
				$(SRC)ft_arrprnt.c \
				$(SRC)ft_list_add_back.c \
				$(SRC)ft_list_add_front.c \
				$(SRC)ft_list_size.c \
				$(SRC)ft_listlast.c \
				$(SRC)ft_lstprnt.c \
				$(SRC)ft_newnode.c \
				$(SRC)ft_sort.c \
				$(SRC)ft_turkish_utils.c \
				$(SRC)ft_turkish_a_to_b.c \
				$(SRC)ft_turkish_b_to_a.c \
				$(SRC)ft_turkish_find_below.c \
				$(SRC)ft_turkish.c \
				$(SRC)fx_push.c \
				$(SRC)fx_rotate_down.c \
				$(SRC)fx_rotate_up.c \
				$(SRC)fx_swap.c \
				$(SRC)initialization.c \
				$(SRC)List_cleaner.c \
				$(SRC)main.c \
				$(SRC)new_list.c \
				$(SRC)parser.c \
				$(SRC)verifs.c \
				$(SRC)ft_atol.c \
				$(SRC)ft_sort_verifier.c \
				$(SRC)ft_string_checker.c

# Object files
OBJECTS		=	$(SOURCES:$(SRC)%.c=$(OBJ_DIR)%.o)

# Compiler and flags
CC			=	cc
LDFLAGS		=	-L$(PRINTF) -L$(LIBFT) -lftprintf -lft
CFLAGS		=	-Wall -Wextra -Werror -g

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJECTS)
	@$(MAKE) -s -C $(LIBFT)
	@$(MAKE) -s -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LDFLAGS)
	@echo "All files were created"

# Rule for building object files
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJ_DIR)
	@echo "Push_Swap object files were cleaned"

# Full clean
fclean: clean
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(PRINTF) clean
	@rm -f $(NAME)
	@echo "All files were cleaned"

# Rebuild everything
re: fclean all

norminette:
	norminette $(SRC)
	norminette $(PRINTF)
	norminette $(LIBFT)

# Phony targets
.PHONY: all clean fclean re