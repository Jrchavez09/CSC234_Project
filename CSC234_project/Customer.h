#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <string>
#include <cstdbool>

#include "Order.h"
#include "OrderList.h"

using std::string;
using std::ostream;


class Customer 
{
	friend ostream& operator<<(ostream&,  const Customer&);

	private:
		string name;
		string address;
		string email;
		OrderList orders;

	public:
		Customer();
		Customer(string _name, string _address,
			 string _email, OrderList _orders);

		OrderList getOrders();
		void AddOrder(Order arg);
		void UpdateOrders(string arg, int n);
		void CancelOrder(string arg, int n);
		
		string getCustomerName();
		string getAddress();
		string getEmail();
		double checkoutOrders();
		
		bool operator==(const Customer& n) const;
		bool operator!=(const Customer& n) const;
		bool checkCustomerName(string _name);

};

#endif // !CUSTOMER_H_INCLUDED

