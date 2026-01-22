#include <iostream>
#include <fstream>
#include <string>


int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << av[0] << " <filename> <s1> <s2>\n";
        return 1;
    }
	av++;
	std::string filename = av[0];
	std::string s1 = av[1];
	std::string s2 = av[2];

	if (s1.empty())
	{
		std::cerr << "<s1> cannot be empty";
		return (1);
	}
	std::ifstream src (filename.c_str());
	if (!src)
	{
		std::cerr << "failed to open " << filename << " verify filename\n";
		return (1);
	}
	std::ofstream dst((filename + ".replace").c_str());
	if (!dst)
	{
		std::cerr << "Failed to create " << filename << ".replace file\n";
		return (1);
	}
	std::string oldline;
	size_t pos;
	while (std::getline(src, oldline))
	{
		pos = 0;
		//std::cout << oldline.find(s1, pos) << '\n';
		while ((pos = oldline.find(s1, pos)) != std::string::npos)
		{
			//std::cout << "oldline=>" << oldline << "<=\n";
			//std::cout << "pos=" << pos << "=\n";
			//std::cout << "substr=>" << oldline.substr(0, pos)<< "<=s2=>" << s2 << "<=";
			dst << oldline.substr(0, pos) << s2;
			oldline = oldline.substr( pos + s1.size());
			//std::cout << "oldlinesub=>" << oldline << "<=\n";
			pos = 0;
		}
		//std::cout << "oldlinefinale=>" << oldline << "<=\n";
		dst << oldline;
		if(!src.eof())
			dst << '\n';
	}
	src.close();
	dst.close();
	return (0);
}
