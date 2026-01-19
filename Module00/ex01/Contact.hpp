#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using namespace std;
class Contact
{
private:
	string firstName;
	string lastName;
	string nickname;
	string phoneNumber;
	string darkestSecret;
public:
	void setFirstName(string& name) { firstName = name; }
	void setLastName(string& name) { lastName = name; }
	void setNickname(string& name) { nickname = name; }
	void setPhoneNumber(string& number) { phoneNumber = number; }
	void setDarkestSecret(string& secret) { darkestSecret = secret; }
	string& getFirstName()  { return firstName; }
	string& getLastName()  { return lastName; }
	string& getNickname()  { return nickname; }
	string& getPhoneNumber()  { return phoneNumber; }
	string& getDarkestSecret()  { return darkestSecret; }
};

#endif