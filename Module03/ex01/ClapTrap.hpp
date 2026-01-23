#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	damage;
	public:
		ClapTrap();// default constructor
		ClapTrap( std::string name );// parameterized constructor
		ClapTrap( const ClapTrap &other );// copy constructor
		ClapTrap &operator=( const ClapTrap &other );// assignment operator
		~ClapTrap();// destructor
		//void getinfo( void );
		void attack( const std::string &target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};



#endif