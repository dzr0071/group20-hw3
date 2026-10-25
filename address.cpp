//implementation code for address struct here
#include <string>
#include "address.h"

using std::string;

//returns a string containing the full address
string address::address_info()
{
  string info = "Address:\n";

  //add each part of the address on its own line
  info += address_line1 + "\n";
  info += address_line2 + "\n";
  info += city + "\n";
  info += state + "\n";
  info += zip + "\n";

  return info;
}
