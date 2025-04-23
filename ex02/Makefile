# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 20:48:38 by kiwasa            #+#    #+#              #
#    Updated: 2025/04/22 20:49:37 by kiwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Account.hpp

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