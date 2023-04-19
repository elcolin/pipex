# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 18:15:04 by ecolin            #+#    #+#              #
#    Updated: 2022/05/04 13:46:11 by ecolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER_SRC	=	pipex.h libft.h
HEADER_DIR	=	includes/
HEADER	=	$(addprefix $(HEADER_DIR), $(HEADER_SRC))

UTILS_DIR = utils/
UTILS = ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strchr.c
UPATH =  $(addprefix $(UTILS_DIR), $(UTILS))
UOBJ = $(UPATH:.c=.o)

SRC_DIR = mandatory/
SRC = main.c pipex.c
SPATH = $(addprefix $(SRC_DIR), $(SRC))
SOBJ = $(SPATH:.c=.o)

%.o: %.c $(HEADER) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(UOBJ) $(SOBJ)
		$(CC) $(CFLAGS) $(UOBJ) $(SOBJ) -o $(NAME)

clean : 
		$(RM) $(UOBJ)
		$(RM) $(SOBJ)

fclean : clean
		/bin/rm -rf $(NAME)
re: fclean all
