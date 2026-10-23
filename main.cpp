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
	//import from text files
	//No more than 100 products, transactions, and customers
	const int max_items = 100;

	//Open the three data files from the assignment
	std::ifstream peopleFile("people.txt");
	std::ifstream cardFile("credit_card.txt");
	std::ifstream productFile("products.txt");

	if (!peopleFile || !cardFile || !productFile)
	{
		std::cerr << "Error: Could not open file.\n";
		return 1;
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
