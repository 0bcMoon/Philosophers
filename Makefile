# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hibenouk <hibenouk@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 09:27:48 by hibenouk          #+#    #+#              #
#    Updated: 2024/07/30 09:13:59 by hibenouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =  main.c init.c  parsing.c  routine.c thread.c time.c clean.c 


OBJ_DIR = ./obj/
SRC_DIR = .

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = cc


CFLAGS = -Wall -Wextra -O3 -Ofast -fsanitize=address 

INC = include

NAME = philo

all : $(NAME)

$(NAME) :$(OBJ_DIR) $(OBJ)
	$(CC)  $(CFLAGS) -I$(INC) $(OBJ) -o $(NAME)


$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
