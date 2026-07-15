#include <iostream>
#include "Serializer.hpp"

void	printdata(Data data)
{
	std::cout << "{ id  = " << data.id << " | api = " << data.link << " }\n";
}

int main(void)
{
	Data		data;
	uintptr_t	s;
	Data		*d;

	data.id = 1337;
	data.link = "https://udeal.site";
	s = 0;
	d = NULL;

	std::cout << "before serialization" << "\n\n";
	std::cout << "data & " << &data << " | => ";
	printdata(data);
	std::cout << "s    & " << &s << " | => " << s << '\n';
	std::cout << "d*   & " << &d << " | => " << d << "\n\n";

	s = Serializer::serialize(&data);
	d = Serializer::deserialize(s);

	std::cout << "after  serialization" << "\n\n";
	std::cout << "data & " << &data << " | => ";
	printdata(data);
	std::cout << "s    & " << &s << " | => " << s <<'\n';
	std::cout << "d*   & " << &d << " | => " << d <<'\n';

	return (0);
}
