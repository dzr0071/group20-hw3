//code for store class here
#include <string>
#include "store.h"

using std::string;

//max number of items each array can hold
const int kMaxSize = 100;

//default constructor, store starts out empty
Store::Store()
{
	num_customers_ = 0;
	num_products_ = 0;
	num_transactions_ = 0;
}

//getters/setters for num_customers_
void Store::num_customers(int customer_count)
{
	num_customers_ = customer_count;
}

int Store::num_customers()
{
	return num_customers_;
}



//getters/setters for num_products_
void Store::num_products(int product_count)
{
	num_products_ = product_count;
}

int Store::num_products()
{
	return num_products_;
}



//getters/setters for num_transactions_
void Store::num_transactions(int transaction_count)
{
	num_transactions_ = transaction_count;
}

int Store::num_transactions()
{
	return num_transactions_;
}

//adds a customer to the next open spot in customers_[].
//returns false if the array is full.
bool Store::add_customer(Person customer)
{
	if (num_customers_ >= kMaxSize)
	{
		return false;
	}
	customers_[num_customers_] = customer;
	num_customers_++;
	return true;
}

//replaces the customer at index with an updated copy.
//returns false if the index is invalid or the customer
//at that index is not the same person.
bool Store::update_customer(int index, Person customer)
{
	if (index < 0 || index >= num_customers_)
	{
		return false;
	}
	if (customers_[index].name() != customer.name() ||
		customers_[index].phone() != customer.phone())
	{
		return false;
	}
	customers_[index] = customer;
	return true;
}

//returns the customer at index, or a default Person
//if the index is invalid
Person Store::get_customer(int index)
{
	if (index < 0 || index >= num_customers_)
	{
		return Person();
	}
	return customers_[index];
}

//adds a product to the next open spot in products_[].
//returns false if the array is full.
bool Store::add_product(product item)
{
	if (num_products_ >= kMaxSize)
	{
		return false;
	}
	products_[num_products_] = item;
	num_products_++;
	return true;
}

//returns the product at index, or an empty product
//if the index is invalid
product Store::get_product(int index)
{
	if (index < 0 || index >= num_products_)
	{
		return product();
	}
	return products_[index];
}

//adds a transaction to the next open spot in transactions_[].
//returns false if the array is full.
bool Store::add_transaction(transaction ntransaction)
{
	if (num_transactions_ >= kMaxSize)
	{
		return false;
	}
	transactions_[num_transactions_] = ntransaction;
	num_transactions_++;
	return true;
}

//returns the transaction at index, or an empty transaction
//if the index is invalid
transaction Store::get_transaction(int index)
{
	if (index < 0 || index >= num_transactions_)
	{
		return transaction();
	}
	return transactions_[index];
}

//charges the customer's credit card for amount of item.
//on success, saves the new balance on the store's copy of
//the customer and records a transaction. returns false if
//the customer isn't in the store, the amount is invalid,
//the transactions_[] is full, or the card is declined.
bool Store::make_purchase(Person customer, product item, int amount)
{
	int index = find_customer(customer);
	if (index == -1 || amount <= 0 || num_transactions_ >= kMaxSize)
	{
		return false;
	}

	//use the store's copy so the balance is always up to date
	Person buyer = customers_[index];
	credit_card card = buyer.person_credit_card();
	if (!card.make_purchase(item.price * amount))
	{
		return false;
	}
	buyer.person_credit_card(card);
	update_customer(index, buyer);

	transaction new_transaction;
	new_transaction.transaction_number = num_transactions_ + 1;
	new_transaction.customer = buyer;
	new_transaction.purchased_item = item;
	new_transaction.quantity = amount;
	return add_transaction(new_transaction);
}

//returns a string listing all products in the store
string Store::product_info()
{
	string info = "Products: \n";
	for (int i = 0; i < num_products_; i++)
	{
		info += products_[i].product_info();
	}
	return info;
}

//returns a string listing all transactions in the store
string Store::transaction_info()
{
	string info = "All Transactions: \n";
	for (int i = 0; i < num_transactions_; i++)
	{
		info += transactions_[i].transaction_info();
	}
	return info;
}

//returns a string listing all customers in the store
string Store::customer_info()
{
	string info = "Customers: \n";
	for (int i = 0; i < num_customers_; i++)
	{
		info += customers_[i].person_info();
	}
	return info;
}

//returns customers, products, and transactions
string Store::store_info()
{
	return customer_info() + "\n" + product_info() + "\n" +
		transaction_info();
}

//returns all transactions that belong to customer
string Store::purchase_history(Person customer)
{
	string history = "Purchase History for " + customer.name() + ": \n";
	for (int i = 0; i < num_transactions_; i++)
	{
		if (transactions_[i].customer.name() == customer.name() &&
			transactions_[i].customer.phone() == customer.phone())
		{
			history += transactions_[i].transaction_info();
		}
	}
	return history;
}

//returns the index of cust in customers_[], matching on
//name and phone. returns 0 if not found.
int Store::find_customer(Person cust)
{
	for (int i = 0; i < num_customers_; i++)
	{
		if (customers_[i].name() == cust.name() &&
			customers_[i].phone() == cust.phone())
		{
			return i;
		}
	}
	return -1;
}

