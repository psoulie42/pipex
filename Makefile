# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 12:48:10 by psoulie           #+#    #+#              #
#    Updated: 2024/11/18 13:51:49 by psoulie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =		

FFILES = 	printf		\
			countargs	\
			putcharn	\
			putstrn		\
			putnbrn		\
			putunbrn	\
			putnbrhexn	\
			putptrn		\

SRCS = $(addprefix ./ft_, $(addsuffix .c, $(FILES)))
FSRCS_DIR = ./ffiles/
FSRCS = $(addprefix $(FSRCS_DIR)ft_, $(addsuffix .c, $(FFILES)))

OFILES = $(SRCS:.c=.o) $(FSRCS:.c=.o)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OFILES) $(FOFILES)
		$(CC) $(CFLAGS) $(NAME)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
