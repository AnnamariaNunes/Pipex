# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aangelic <aangelic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 12:10:48 by aangelic          #+#    #+#              #
#    Updated: 2023/05/20 15:58:04 by aangelic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := 	main.c \
			pipex_utils.c \

OBJS := $(SRCS:.c=.o)
NAME := pipex
CC := cc
CFLAGS :=  -g -Wall -Werror -Wextra   -I LIBFT/ -I . -fsanitize=address
RM := rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	make -C LIBFT/
	$(CC) $(CFLAGS) $(OBJS) LIBFT/libft.a -o pipex

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean : 
	$(RM) $(OBJS)
fclean : clean
	make fclean -C LIBFT/
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re 