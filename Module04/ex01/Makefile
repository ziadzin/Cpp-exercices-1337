NAME = brain
CXX = c++
CXXFLGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
HEADERS = $(wildcard *.hpp)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re