# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 09:27:48 by hibenouk          #+#    #+#              #
#    Updated: 2024/07/30 11:45:48 by hibenouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =  main.c init.c  parsing.c  routine.c thread.c time.c clean.c outils.c 


OBJ_DIR = ./obj/
SRC_DIR = .

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = cc


CFLAGS = -O3 -Ofast  -Wall -Wextra 


NAME = philo

all : $(NAME)

$(NAME) :$(OBJ_DIR) $(OBJ)
	$(CC)  $(CFLAGS)  $(OBJ) -o $(NAME)


$(OBJ_DIR)%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
