#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;
		int		nextIndex;
	public:
		PhoneBook();
		void			addContact(const Contact& contact);
		int				getContactCount() const;
		const Contact&	getContact(int index) const;
};
void	add_contact(PhoneBook& pb);
void	search_contacts(PhoneBook& pb);

#endif
