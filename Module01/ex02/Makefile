NAME = brain
CXX = c++
CXXFLGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


#	std::string* stringPTR = &brain;
#	std::string& stringREF = brain;

#	std::cout << "Address of brain: " << &brain << std::endl;
#	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
#	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

#	std::cout << "Value of brain: " << brain << std::endl;
#	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
#	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;