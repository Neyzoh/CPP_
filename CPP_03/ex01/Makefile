FLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = ScavTrap
CC = c++
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
HEADER = ClapTrap.hpp ScavTrap.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
