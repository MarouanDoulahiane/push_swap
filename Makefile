# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 09:13:15 by mdoulahi          #+#    #+#              #
#    Updated: 2023/12/03 17:47:13 by mdoulahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		main.c setup_stack.c setup_stack_helper.c stack_tools.c \
				ft_strjoin_new.c ft_split.c setup_longest.c setup_longest_helper.c \
				push_to_b.c actions_1.c actions_2.c actions_3.c actions_4.c \
				push_to_a.c ft_atol.c push_to_a_helper.c handle_empty.c \


SRCB	=		checker.c setup_stack.c setup_stack_helper.c stack_tools.c \
				ft_strjoin_new.c ft_split.c setup_longest.c setup_longest_helper.c \
				push_to_b.c bonus/actions_1.c bonus/actions_2.c bonus/actions_3.c bonus/actions_4.c \
				push_to_a.c ft_atol.c push_to_a_helper.c  get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c handle_empty.c \

OBJ		=		$(SRC:.c=.o)

OBJB	=		$(SRCB:.c=.o)

NAME	=		push_swap

BONUS_NAME	=	checker

CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

RM 		= 		rm -fr

all: 	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJB)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJB)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: 	fclean all

.PHONY:	clean