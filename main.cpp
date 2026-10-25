#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{
	
	//No more than 100 products, transactions, and customers
	const int max = 100;

	//Arrays to hold info read from files
	Person people[max];
	credit_card cards[max];
	product products[max];

	int numPeople = 0;
	int numCards = 0;
	int numProducts = 0;

	//import from text files

	//Open the three data files from the assignment
	ifstream peopleFile("people.txt");
	ifstream cardFile("credit_card.txt");
	ifstream productFile("products.txt");

	//stop program if file cannot be open
	if (!peopleFile || !cardFile || !productFile)
	{
		std::cerr << "Error: Could not open file.\n";
		return 1;
	}

	//Read credit cards first so we can give one to each person
	//The first nmber in the file tells how many cards there are
	cardFile >> numCards;
	if (!cardFile || numCards < 1 || numCards > max)
	{
		cout << "Error: Invalid number of credit cards." << endl;
		return 1;
	}

	for (int i = 0; i < numCards; i++)
		{
			//Each card has a number, credit limit, and current balance
			cardFile >> cards[i].cc_number;
			cardFile >> cards[i].limit;
			cardFile >> cards[i].current_balance;

			if (!cardFile)
			{
				cout << "Error: cold not read credit card information." << endl;
				return 1;
			}
		}

	//Read number of people at the top of people.txt
	peopleFile >> numPeople;
	if (!peopleFile || numPeople < 1 || numPeople > max)
	{
		cout << "Error: Invalid number of people." << endl;
		return 1;
	}

	//Each person needs a credit card --> counts must match
	if (numPeople != numCards)
	{
		cout << "Error: The number of people and credit cards does not match." << endl;
		return 1;
	}

	for (int i = 0; i < numPeople; i++)
		{
			string name;
			string phone;
			address home;

			//getline reads a whole line, including names with spaces
			//also need it for the sometimes empty second address line
			getline(peopleFile, name);
			getline(peopleFile, phone);
			getline(peopleFile, home.address_line1);
			getline(peopleFile, home.address_line2);
			getline(peopleFile, home.city);
			getline(peopleFile, home.state);
			getline(peopleFile, home.zip);

			if (!peopleFile)
			{
				cout << "Error: Could not read person information." << endl;
				return 1;
			}

			//create a person using info just read
			//credit card and person belong to same index value i
			people[i] = Person(name, phone, home, cards[i]);
		}

	//read products from product.txt
	productFile >> numProducts;
	if (!productFile || numProducts < 1 || numProducts > max)
	{
		cout << "Error: Invalid number of products." << endl;
		return 1;
	}

	for (int i = 0; i < numProducts; i++)
		{
			//each product has a name, description, and price
			getline(productFile, products[i].name);
			getline(productFile, products[i].description);
			productFile >> products[i].price;

			if (!productFile)
			{
				cout << "Error: Could not read product information." << endl;
				return 1;
			}
		}

	//add to store and other variables

	//create store that will hold customers and products

	Store store1;

		for (int i = 0; i < numPeople; i++)
			{
				if (!store1.add_customer(people[i]))
					{
					cout << "Error: Could not add a customer to the store." << endl;
					return 1;
				}
			}

		for (int i = 0; i < numProducts; i++)
			{
				if (!store1.add_product(products[i]))
				{
					cout << "Error: Could not add a product to the store." << endl;
					return 1;
				}
			}

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//set up random numbers and choose between 11 and 99 purchase attempts
	srand(time(0));
	int numAttempts = rand() % 89 + 11;

	for (int i = 0; i < numAttempts; i++)
		{
			//pick a random customer and product from the store
			int customerIndex = rand() % store1.num_customers();
			int productIndex = rand() % store1.num_products();

			//pick quantity from 1 - 9
			int quantity = rand() % 9 + 1;

			//Get the customer's latest information from the store
			//their balance might have changed from an earlier purchase
			Person customer = store1.get_customer(customerIndex);
			product item = store1.get_product(productIndex);

			//try to buy item and see if purchase succeeds
			bool success = store1.make_purchase(customer, item, quantity);

			if (success)
			{
				cout << "Successful transaction!" << endl;
				cout << "Transaction details:" << endl;


				//The last transaction in the store is the one that was just made
				int lastIndex = store1.num_transactions() - 1;
				transaction latest = store1.get_transaction(lastIndex);
				cout << latest.transaction_info() << endl << endl;
			}
			else
			{
				//a failed purchase is not saved as a completed transaction so print the info about the attempt here
				cout << "Unsuccessful transaction." << endl;
				cout << "Transaction details:" << endl;
				cout << "Person:" << endl;
				cout << customer.person_info() << endl;
				cout << "Product:" << endl;
				cout << item.product_info() << endl;
				cout << "Purchase quantity: " << quantity << endl << endl;
			}
		}
			
	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
