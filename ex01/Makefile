# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 19:13:32 by kiwasa            #+#    #+#              #
#    Updated: 2025/04/22 20:40:58 by kiwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = phoneBook.cpp contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = phoneBook.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re