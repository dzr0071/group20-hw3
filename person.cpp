//code for person class here
#include <string>
#include "person.h"

using std::string;

//constructor that creates a person using the info given
Person::Person(string person_name, string person_phone, address home, credit_card card)
{
  name_ = person_name;
  phone_ = person_phone;
  person_address_ = home;
  person_credit_card_ = card;
}

//default constructor that creates a person with empty information
Person::Person()
{
  name_ = "";
  phone_ = "";
  person_address_ = address();
  person_credit_card_ = credit_card();
}

//set person name
void Person::name(string person_name)
{
  name_ = person_name;
}

//returns the person's name
string Person::name()
{
  return name_;
}

//set person phone number
void Person::phone(string person_phone)
{
  phone_ = person_phone;
}

//return person's phone number
string Person::phone()
{
  return phone_;
}

//set person's address
void Person::person_address(address home)
{
  person_address_ = home;
}

//returns the person's address
address Person::person_address()
{
  return person_address_;
}

//sets the person's credit card info
void Person::person_credit_card(credit_card card)
{
  person_credit_card_ = card;
}

//return credit card info
credit_card Person::person_credit_card()
{
  return person_credit_card_;
}

//return person's info as one string
string Person::person_info()
{
  string info = "Name: " + name_ + "\n";
  info += "Phone: " + phone_ + "\n";

//use other structs' functions to add their info
info += person_address_.address_info();
info += "Credit Card:\n";
info += person_credit_card_.credit_card_info();

return info;
}
