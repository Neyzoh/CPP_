FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = human

CC = c++

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp  

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
    
re:	fclean $(NAME)