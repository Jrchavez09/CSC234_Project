#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdbool>

#include "CustomerList.h"


using namespace std;


ostream& operator<<(ostream& os, const CustomerList& customer)
{
	customer.print();
	return (os);
}


void
CustomerList::AddCustomer(Customer& customer)
{
	insertLast(customer);
}


bool
CustomerList::searchCustomerByName(string searchName) const
{
	bool found = false;
	nodeType<Customer> *location;

	searchCustomerByNameHelper(searchName, found, location);

	return (found);
}


void
CustomerList::searchCustomerByNameHelper(string searchName,
	bool found, nodeType<Customer>* &current) const
{
	found = false;
	current = first;

	
	while (current != nullptr && !found) {
		if (current->info.checkCustomerName(searchName)) {
			found = true;
		} else {
			current = current->link;
		}
	}
}


Customer
CustomerList::getCustomerByName(string _name) const
{
	Customer n;
	return n;
}


void
CustomerList::UpdateCustomer(Customer& current)
{
	return;
}


void
CustomerList::UpdateDataFile(ofstream& file)
{
	nodeType<Customer> *current = first;

	while (current != nullptr) {
		file << current->info.getCustomerName() << endl
		     << current->info.getAddress() << endl
		     << current->info.getEmail() << endl;
		current = current->link;
	}
	return;
}