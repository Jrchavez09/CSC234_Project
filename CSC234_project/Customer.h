#ifndef Customer_H
#define Customer_H

#include <string>
#include <cstdbool>

#include "Order.h"
#include "OrderList.h"

using std::string;
using std::ostream;


class Customer 
{
	friend ostream& operator<<(ostream&,  const Customer);

	private:
		string name;
		string address;
		string email;
		OrderList orders;

	public:
		Customer() : name(""), address(""), email("") { }
		
		Customer(string _name, string _address,
					string _email, OrderList _orders) :
			name(_name),
			address(_address),
			email(_email),
			orders(_orders) { }

		OrderList getOrders()
		{
			return (orders);
		}

		void AddOrder(Order arg) { return;  }
		
		
		void
		UpdateOrders(string arg, int n)
		{
			return;
		}
		
		
		void
		CancelOrder(string arg, int n)
		{
			return;
		}

		string getCustomerName() { return (name); }
		string getAddress() { return (address); }
		string getEmail() { return (email); }
		double checkoutOrders() { return (0.0); }
		
		bool
		operator==(const Customer& n) const
		{
			return (name == n.name || address == n.address
				|| email == n.email);
		}


		bool
		operator!=(const Customer& n) const
		{
			return (name != n.name || address != n.address
				|| email != n.email);
		}
};

#endif // !Customer_H

