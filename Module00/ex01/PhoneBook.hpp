#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "Contact.hpp"

using namespace std;

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;
		int		nextIndex;
	public:
		PhoneBook() : contactCount(0), nextIndex(0) {}
		void addContact(Contact& contact)
		{
			contacts[nextIndex] = contact;
			nextIndex = (nextIndex + 1) % 8; 
			std::cout << nextIndex << '\n';
			if (contactCount < 8)
				contactCount++;
		}
		int getContactCount() { return contactCount; }
		Contact& getContact(int index) { return contacts[index]; }
};
void	add_contact(PhoneBook& pb);
void	search_contacts(PhoneBook& pb);

#endif