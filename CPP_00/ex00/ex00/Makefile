# Nom de l'exécutable
NAME = megaphone

# Compilateur et flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS = megaphone.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compilation des fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
