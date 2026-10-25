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

	

	//add to store and other variables

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions

	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
}
