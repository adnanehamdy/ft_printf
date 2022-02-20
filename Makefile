# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 14:14:05 by ahamdy            #+#    #+#              #
#    Updated: 2021/11/24 16:03:10 by ahamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr_base.c ft_putnbr.c ft_functions.c

NAME = libftprintf.a

AR = ar rs

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all

.PHONY : all clean fclean