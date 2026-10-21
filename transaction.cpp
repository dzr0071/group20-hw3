//code for transaction struct here
#include <string>
#include <sstream>
#include "transaction.h"

using std::string;
using std::ostringstream;

//returns the transaction number, the customer, the product
//purchased, and how many were bought
string transaction::transaction_info()
{
	ostringstream out;
	out << "Transaction #: " << transaction_number << "\n";
	out << "Customer: \n";
	out << customer.person_info();
	out << "Product: \n";
	out << purchased_item.product_info();
	out << "Quantity: " << quantity << "\n";
	return out.str();
}
