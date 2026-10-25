//code for product struct here
#include <string>
#include <sstream>
#include <iomanip>
#include "product.h"

using namespace std;

//return product info as a string
string product::product_info()
{
  stringstream info;

  info << "Name: " << name << "\n";
  info << "Description: " << description << "\n";
  info << "Price: $" << fixed << setprecision(2) << price << "\n";

  return info.str();
}
