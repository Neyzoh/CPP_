FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = phonebook

CC = c++

SRCS = main.cpp contact.cpp phonebook.cpp

HEADER = contact.hpp phonebook.hpp

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