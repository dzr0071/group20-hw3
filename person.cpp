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
