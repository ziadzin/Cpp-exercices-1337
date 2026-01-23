NAME = claptrap
CXX = c++
CXXFLGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
