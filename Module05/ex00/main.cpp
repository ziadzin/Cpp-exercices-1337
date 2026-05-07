#include "Bureaucrat.hpp"

int main()
{
   try
    {
        // Bureaucrat f("ziad", 1);
        // Bureaucrat a("test", 150);
        Bureaucrat a("user", 1);
        Bureaucrat z;
        // z = a;
        z.raiseGrade();
        z.lowerGrade();
        // z.lowerGrade();
        std::cout << z << '\n';
        // std::cout << a << '\n';
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << '\n';
    }
    return 0;
}
