NAME	= megaphone
CXX		= c++
CXXFLGS = -Wall -Werror -Wextra -std=c++98
SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	$(CXX) $(CXXFLGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re