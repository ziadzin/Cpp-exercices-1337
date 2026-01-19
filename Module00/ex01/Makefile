NAME	= phonebook
CXX		= c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC		= main.cpp PhoneBook.cpp
HDR		= PhoneBook.hpp Contact.hpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re