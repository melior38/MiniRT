# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 08:45:50 by lcamilo-          #+#    #+#              #
#    Updated: 2023/09/11 12:42:11 by asouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

# ------------  PROJECT  ----------------------------------------------------- #
NAME		= MiniRT

# ------------  DIRECTORIES  ------------------------------------------------- #
LIB				= libftprintfgnl
SRC_PATH		= src/
HEADERS			= includes
HEADERS_LIB		= libftprintfgnl/includes

INC			= $(addprefix $HEADERS_LIB)

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -I $(HEADERS) -I $(HEADERS_LIB) -fsanitize=address -Werror -Wextra -Wall -I ./mlx
CC			= @cc
RM			= rm -rf

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		= 	main.c							\
				parsing/ft_atod.c				\
				parsing/parsing.c				\
				parsing/parse_init.c			\
				parsing/get_function.c			\
				parsing/parsing_utils.c

# ------------  FILEPATHS  --------------------------------------------------- #
OBJS				= ${SRC:.c=.o}
OBJS_DIR			= objs
DIRS				= objs objs/parsing
_OBJS				= $(addprefix $(OBJS_DIR)/, $(OBJS))

all: lib $(NAME)

lib:
			@echo "$(COLOUR_CYAN)Compilation libft..."
			make -C $(LIB)
			@echo "$(COLOUR_YELLOW)Deplacement du libft.a $(COLOUR_END)"
			@cp ./libftprintfgnl/libft.a libft.a

$(NAME): $(_OBJS)
			@echo "$(COLOUR_CYAN)Compile..."
			$(CC) $(_OBJS) libft.a $(CFLAGS) -o $@ -L libftprintfgnl -lft -I ./mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit
			@echo "$(COLOUR_RED)MiniRT ready. $(COLOUR_END)"

$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c
		@mkdir -p $(DIRS)
		${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			$(RM) ${_OBJS}
			make fclean -C $(LIB)

fclean:		clean
			$(RM) $(NAME) *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(PRINTF)