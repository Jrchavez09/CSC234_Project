#ifndef OrderList_H
#define OrderList_H

#include <iostream>
#include <cstdbool>
#include <fstream>

#include "LinkedList.h"
#include "Order.h"

class OrderList : public linkedListType<Order>
{
	friend ostream& operator<<(ostream& os, const OrderList& orders)
	{
		orders.print();
		return (os);
	}

	public:
		void
		AddOrder(Order& _order)
		{
			insertLast(_order);
		}


		void
		UpdateOrder(string _title, int _number)
		{
			bool found = false;
			nodeType<Order>* location;

			searchOrderList(_title, found, location);

			if (found) {
				location->info.setNumber(_number);
				cout << "The order is updated." << endl;
			}
			else {
				cout << "Order is not found." << endl;
			}
		}


		void
		CancelOrder(string title)
		{
			bool found = false;
			nodeType<Order>* current = first;

			searchOrderList(title, found, current);
			deleteNode(current->info);

			return;
		}


		double
		CalculateSubtotal()
		{
			nodeType<Order>* current = first;
			double subtotal = 0.0;
			
			while (current != nullptr) {
				subtotal += (current->info.calculateCost());
				current = current->link;
			}

			return (subtotal);
		}
		
		
		void
		UpdateDataFile(ofstream& file)
		{
			nodeType<Order>* current = first;

			while (current != nullptr) {
				file << current->info.getTitle() << endl
					 << current->info.getPrice() << endl
					 << current->info.getNumber() << endl;
					
				current = current->link;
			}
		}
	
	private:
		void
		searchOrderList(string title, bool& found,
			nodeType<Order>*& current) const
		{
			found = false;
			current = first;

			while (current != nullptr && !found) {
				if (current->info.checkTitle(title)) {
					found = true;
				}
				else {
					current = current->link;
				}
			}
		}
};
#endif // !OrderList_H

