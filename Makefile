# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 15:43:30 by edpaulin          #+#    #+#              #
#    Updated: 2021/08/09 22:35:58 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	get_next_line

SRC					=	get_next_line.c \
						get_next_line_utils.c
SRC_BONUS			=	get_next_line_bonus.c \
						get_next_line_utils_bonus.c
OBJ					=	$(SRC:.c=.o)
OBJ_BONUS			=	$(SRC_BONUS:.c=.o)
HEADER_DIR			=	.

CC					=	clang
CFLAGS				=	-Wall -Wextra -Werror

.DEFAULT_GOAL		=	all

all:		$(NAME)

bonus:		$(OBJ) $(OBJ_BONUS)
	ar cr $(NAME) $(OBJ) $(OBJ_BONUS)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(NAME):	$(OBJ)
	ar cr $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:		clean
	rm -f $(NAME)

re:			fclean	all

rebonus:	fclean	bonus