FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = zombie

CC = c++

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

HEADER = Zombie.hpp 
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