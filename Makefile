# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 12:48:10 by psoulie           #+#    #+#              #
#    Updated: 2024/11/19 11:42:11 by psoulie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =		pipex		\

FFILES = 	printf		\
			countargs	\
			putcharn	\
			putstrn		\
			putnbrn		\
			putunbrn	\
			putnbrhexn	\
			putptrn		\
			split		\
			strjoin		\
			strnstr		\

SRCS = $(addsuffix .c, $(FILES))
FSRCS_DIR = ./ffiles/
FSRCS = $(addprefix $(FSRCS_DIR)ft_, $(addsuffix .c, $(FFILES)))

OFILES = $(SRCS:.c=.o) $(FSRCS:.c=.o)

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
EXFILE = pipex

all: $(NAME)

$(NAME): $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
