NAME = replace
CXX = c++
CXXFLGS = -Wall -Wextra -Werror -w -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = 

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
