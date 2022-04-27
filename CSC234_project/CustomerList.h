#ifndef CustomerList_H
#define CustomerList_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "LinkedList.h"
#include "Customer.h"

using namespace std;


class CustomerList : public linkedListType<Customer>
{
	friend ostream& operator<<(ostream& os, const CustomerList& customer)
	{
		customer.print();
		return (os);
	}

	public:
		void
		AddCustomer(Customer& customer)
		{
			insertLast(customer);
		}


		bool
		searchCustomerByName(string searchName) const
		{
			bool found = false;

			return (found);
		}


		Customer
		getCustomerByName(string _name) const
		{
			Customer n;
			return n;
		}


		void
		UpdateCustomer(Customer& _customer)
		{
			return;
		}


		void
		UpdateDataFile(ofstream& file)
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
};

#endif // !CustomerList_H

