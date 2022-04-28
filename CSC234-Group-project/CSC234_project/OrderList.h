#ifndef OrderList_H
#define OrderList_H

#include <iostream>
#include <cstdbool>
#include <fstream>

#include "LinkedList.h"
#include "Order.h"


class OrderList : public linkedListType<Order>
{
	friend ostream& operator<<(ostream& os, const OrderList& orders);

	public:
		void AddOrder(Order&);
		void UpdateOrder(string, int);
		void CancelOrder(string);
		double CalculateSubtotal();
		void UpdateDataFile(ofstream&);
	private:
		void SearchOrderList(string title, bool& found,
				     nodeType<Order>*& current) const;
};

#endif // !OrderList_H

