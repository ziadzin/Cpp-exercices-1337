#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

void	PhoneBook::addContact(const Contact& contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;
}

int	PhoneBook::getContactCount() const { return contactCount; }

const Contact&	PhoneBook::getContact(int index) const { return contacts[index]; }

// Returns false on EOF (Ctrl+D) so the caller can stop cleanly.
bool	enter_data(const std::string& data, std::string& field)
{
	std::cout << ">" << data << ": ";
	if (!std::getline(std::cin, field))
		return false;
	if (field.empty())
		return enter_data(data, field);
	for (size_t i = 0; i < field.length(); i++)
	{
		unsigned char c = field[i];
		if (data == "PhoneNumber" && !std::isdigit(c))
			std::cout << "In [" << data << "] only numbers are valid\n";
		else if ((data == "FirstName" || data == "LastName") && !std::isalpha(c))
			std::cout << "In [" << data << "] only alphabets are valid\n";
		else if ((data == "NickName" || data == "DarkestSecret") && !std::isalnum(c))
			std::cout << "In [" << data << "] only alphabets and numbers are valid\n";
		else
			continue ;
		return enter_data(data, field);
	}
	return true;
}

void	add_contact(PhoneBook& pb)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	if (!enter_data("FirstName", firstName)
		|| !enter_data("LastName", lastName)
		|| !enter_data("NickName", nickname)
		|| !enter_data("PhoneNumber", phoneNumber)
		|| !enter_data("DarkestSecret", darkestSecret))
	{
		std::cout << '\n';
		return ;
	}
	Contact newContact;
	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickname(nickname);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecret(darkestSecret);

	pb.addContact(newContact);
	std::cout << "Contact added successfully!\n";
}

std::string	trunc_field(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	display_contact_row(int index, const Contact& contact)
{
	std::cout << 		std::setw(10) << index;
	std::cout << "|" << std::setw(10) << trunc_field(contact.getFirstName());
	std::cout << "|" << std::setw(10) << trunc_field(contact.getLastName());
	std::cout << "|" << std::setw(10) << trunc_field(contact.getNickname());
	std::cout << "|\n";
}

void	display_contact_details(const Contact& contact)
{
	std::cout << "First Name: " << contact.getFirstName() << '\n';
	std::cout << "Last Name: " << contact.getLastName() << '\n';
	std::cout << "Nickname: " << contact.getNickname() << '\n';
	std::cout << "Phone Number: " << contact.getPhoneNumber() << '\n';
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << '\n';
}

void	index_prompt(PhoneBook& pb)
{
	std::cout << "Enter Index >";
	std::string	index;
	if (!std::getline(std::cin, index))
	{
		std::cout << '\n';
		return ;
	}
	if (index.length() == 1 && std::isdigit(static_cast<unsigned char>(index[0]))
		&& index[0] - '0' < pb.getContactCount())
		return display_contact_details(pb.getContact(index[0] - '0'));
	std::cout << "Invalid index: valid range is 0 to " << pb.getContactCount() - 1 << '\n';
}

void	search_contacts(PhoneBook& pb)
{
	if (pb.getContactCount() == 0)
	{
		std::cout << "PhoneBook is empty, use ADD first\n";
		return ;
	}
	std::cout << 		std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FirstName";
	std::cout << "|" << std::setw(10) << "LastName";
	std::cout << "|" << std::setw(10) << "NickName";
	std::cout << "|\n";
	for (int i = 0; i < pb.getContactCount(); i++)
		display_contact_row(i, pb.getContact(i));
	index_prompt(pb);
}
