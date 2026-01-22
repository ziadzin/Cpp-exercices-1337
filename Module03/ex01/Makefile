NAME = ScavTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
HEADERS = $(wildcard *.hpp)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re