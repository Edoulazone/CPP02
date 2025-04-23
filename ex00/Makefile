# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 15:19:00 by eschmitz          #+#    #+#              #
#    Updated: 2025/04/23 12:43:28 by eschmitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = relou

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Fixed.cpp

OBJ = $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all