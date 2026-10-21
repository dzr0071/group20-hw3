//implementation code for credit_card struct here
#include <string>
#include <sstream>
#include <iomanip>
#include "credit_card.h"

using std::string;
using std::ostringstream;
using std::fixed;
using std::setprecision;

//attempts to charge purchase_amount to the card.
//fails if the amount is not positive or if it
//would push the balance over the credit limit.
bool credit_card::make_purchase(double purchase_amount)
{
	if (purchase_amount <= 0)
	{
		return false;
	}
	if (current_balance + purchase_amount > limit)
	{
		return false;
	}
	current_balance += purchase_amount;
	return true;
}

//attempts to pay payment_amount towards the balance.
//fails if the amount is not positive or if it is
//more than what is currently owed.
bool credit_card::make_payment(double payment_amount)
{
	if (payment_amount <= 0)
	{
		return false;
	}
	if (payment_amount > current_balance)
	{
		return false;
	}
	current_balance -= payment_amount;
	return true;
}

//returns the credit card details as a string using stringstream.
string credit_card::credit_card_info()
{
	ostringstream out;
	out << fixed << setprecision(2);
	out << "Credit card number: " << cc_number << "\n";
	out << "Credit Card Limit: $" << limit << "\n";
	out << "Current Balance: $" << current_balance << "\n";
	return out.str();
}

