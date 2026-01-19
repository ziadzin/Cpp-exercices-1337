#include "PhoneBook.hpp"

void	enter_data(const string data, string& field)
{
	cout << ">" << data << ": ";
	if (!std::getline(std::cin, field))
	{
		std::cout << "\nGoodbye!\n";
		exit(0);
	}
	if (field.empty())
		return enter_data(data, field);
	int i = -1;
	while (field[++i])
	{
		if (data == "PhoneNumber" && !isdigit(field[i]))
			cout << "In [" << data << "] only numbers are valid\n";
		else if ((data == "FirstName" || data == "LastName") && !isalpha(field[i]))
			cout << "In [" << data << "] only alphabets are valid\n";
		else if ((data == "NickName" || data == "DarkestSecret") && !isalnum(field[i]))
			cout << "In [" << data << "] only alphabets and numbers are valid\n";
		else
			continue ;
		return enter_data(data, field);
	}
	return ;
}

void	add_contact(PhoneBook& pb)
{
	string firstName, lastName, nickname, phoneNumber, darkestSecret;
	enter_data("FirstName", firstName);
	enter_data("LastName", lastName);
	enter_data("NickName", nickname);
	enter_data("PhoneNumber", phoneNumber);
	enter_data("DarkestSecret", darkestSecret);
	Contact newContact;
	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickname(nickname);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecret(darkestSecret);

	pb.addContact(newContact);
	std::cout << "Contact added successfully!\n";
}

string	trunc_field(string& field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	display_contact_row(int index, Contact& contact)
{
	std::cout << setw(10) << index;
	std::cout << "|" << setw(10) << trunc_field(contact.getFirstName());
	std::cout << "|" << setw(10) << trunc_field(contact.getLastName());
	std::cout << "|" << setw(10) << trunc_field(contact.getNickname());
	std::cout << "|\n";
}

void	display_contact_details(Contact& contact)
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
		return ;
	if(index.length() == 1)
	{
		if (!isdigit(index[0]))
			cout << "Index can only be a digit\n";
		else if ((index[0] - '0') > 7)
			cout << "Index[" << (index[0] - '0') << "]is out of [0]->[7]range\n";
		else if ((index[0] - '0') >= pb.getContactCount() && cout << "No Contact with index[" << (index[0] - '0') << "]\n")
			return ;
		else
			return display_contact_details(pb.getContact(index[0] - '0'));
	}
	return index_prompt(pb);
}

void	search_contacts(PhoneBook& pb)
{
	std::cout << setw(10) << "INDEX";
	std::cout << "|" << setw(10) << "FirstName";
	std::cout << "|" << setw(10) << "LastName";
	std::cout << "|" << setw(10) << "NickName";
	std::cout << "|" << setw(10) << '\n';
	int i = 0;
	while(i < 8)
	{
		display_contact_row(i, pb.getContact(i));
		i++;
	}
	index_prompt(pb);
}