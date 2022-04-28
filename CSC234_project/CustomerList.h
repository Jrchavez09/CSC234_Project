#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

#include "LinkedList.h"
#include "Customer.h"

using namespace std;


class CustomerList : public linkedListType<Customer>
{
	friend ostream& operator<<(ostream& os, const CustomerList& customer);
	public:
		void AddCustomer(Customer& customer);
		bool searchCustomerByName(string searchName) const;
		void searchCustomerByNameHelper(string searchName,
			bool found, nodeType<Customer>* &current) const;

		Customer getCustomerByName(string _name) const;

		void UpdateCustomer(Customer& current);
		void UpdateDataFile(ofstream& file);
};

#endif // !CUSTOMERLIST_H_INCLUDED
