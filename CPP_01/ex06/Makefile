FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = harlFilter

CC = c++

SRCS = main.cpp Harl.cpp 

HEADER = Harl.hpp
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