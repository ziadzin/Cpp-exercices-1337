#include <iostream>

int main(int ac, char **av)
{
	if(ac < 2)	return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0;
	av++;
	while (*av)
	{
		std::string word = *av;
		while (**av)
			std::cout << (char)std::toupper(*(*av)++);
		av++;	
	}
	std::cout << '\n';
	return 0;
}