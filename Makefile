# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/06 13:30:40 by akorol            #+#    #+#              #
#    Updated: 2019/07/06 13:30:42 by akorol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = main.c \
fill_structures.c \
read_name.c \
read_comment.c \
read_instructions.c \
lable_handle.c\
valid_invalid_chars.c\
operation_handle.c\
operation_handle_2.c\
help_functions.c \
arguments_handle.c \
live_op.c \
load.c \
handle_load_index.c \
store_index.c \
handle_add.c \
handle_and.c \
handle_and_2.c \
handle_aff.c \
handle_store.c \
comment_check.c \
writing_to_file.c \
execution_code.c \
execution_code_2.c \
store_index_2.c \
write_direct.c \
comm_to_file.c \
help_functions_2.c \

# op_check.c \
# label_check.c \
# store_index_3.c \
# delete_comments.c \
# load_2.c \
# buf_manager.c \
# line_manipulation.c \

FLAGS = -Wall -Wextra -Werror

LIB = libft/libftprintf.a

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LIB)

$(OBJ):%.o:%.c
	gcc $(FLAGS) -c $< -o $@

$(LIB):
	make -C libft

clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all