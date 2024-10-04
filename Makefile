# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etom <etom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 16:52:47 by toferrei          #+#    #+#              #
#    Updated: 2024/10/04 02:23:04 by etom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PushSwap

LIBFT		=	Libft/
PRINTF		=	Ft_printf/
LIBFT_A		=	$(LIBFT)libft.a
PRINTF_A	=	$(PRINTF)libftprintFf.a
SOURCES		=	$(shell find $(SRC) -maxdepth 1 -name "*.c")

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I$(PRINTF) -I$(LIBFT) 
LDFLAGS = -L$(PRINTF) -L$(LIBFT)

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJECTS)
	$(MAKE) -s -C $(LIBFT)
	$(MAKE) -s -C $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)
	@echo "All files were created"

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS)
	@echo "Fdf files were cleaned"

# Full clean
fclean: clean
	$(MAKE) -s -C $(LIBFT) fclean
	$(MAKE) -s -C $(PRINTF) clean
	rm -f $(NAME)
	@echo "All files were cleaned"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re