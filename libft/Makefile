# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 13:19:37 by akorol            #+#    #+#              #
#    Updated: 2019/06/30 12:03:26 by akorol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

ADDLIB = $(addprefix libft/, libft.a)

LIB = libft/

SRC =   check.c\
		conv_c.c\
		conv_o.c\
		conv_u.c\
		conv_u_2.c\
		customize.c\
		f_shit.c\
		f_string.c\
		filling.c\
		nan_inf.c\
		piece.c\
		piece_hex.c\
		piece_hex_2.c\
		pre_tuner.c\
		process_c.c\
		process_d.c\
		process_d_2.c\
		process_p.c\
		process_s.c\
		process_s_2.c\
		processing2.c\
		test.c\
		tuner.c\
		tuning_f.c\
		zero_case.c\
		new_f_file.c\

CFLAGS = -Wextra -Wall -Werror

LIBFT = ar -rc

HEADER = ft_printf.h

OBJ = $(SRC:%.c=%.o)

# OBJ2 = $(libft/:%.c=%.o)

all: $(NAME)

$(NAME):$(ADDLIB) $(OBJ)
	$(LIBFT) $@ $(OBJ) $(LIB)*.o
	ranlib $(NAME)

$(OBJ):%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

$(ADDLIB):
	make -C libft/

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: clean fclean re all
