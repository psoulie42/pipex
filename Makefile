# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 12:48:10 by psoulie           #+#    #+#              #
#    Updated: 2024/11/28 13:55:55 by psoulie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =		pipex		\

BFILES =	pipex_bonus	\
			here_doc	\

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
			strlen		\
			strcmp		\
			get_next_line/get_next_line\
			get_next_line/get_next_line_utils\

SRCS_DIR = ./
FSRCS_DIR = ./ffiles/
BSRCS_DIR = ./bonus/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
BSRCS = $(addprefix $(BSRCS_DIR), $(addsuffix .c, $(BFILES)))
FSRCS = $(addprefix $(FSRCS_DIR)ft_, $(addsuffix .c, $(FFILES)))

OFILES = $(SRCS:.c=.o) $(FSRCS:.c=.o)
BOFILES = $(BSRCS:.c=.o) $(FSRCS:.c=.o)

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
EXFILE = pipex

all: $(NAME)

bonus: $(BOFILES)
		$(CC) $(CFLAGS) $(BOFILES) -o $(NAME)

$(NAME): $(OFILES)
		$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

clean:
		rm -f $(OFILES) $(BOFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re
