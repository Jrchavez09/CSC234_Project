/* *
 * Source.cpp
 */
#include <iostream>
#include <cstdlib>

#include "LinkedList.h"
#include "Customer.h"
#include "CustomerList.h"
#include "Order.h"
#include "OrderList.h"

using namespace std;

void LoadCustomers(ifstream&, CustomerList&);
int SelectMenu();
void PlaceOrder(CustomerList&);
void UpdateOrder(CustomerList&);
void CancelOrder(CustomerList&);
void PrintOrders(CustomerList&);
void CheckoutOrders(CustomerList&);
void UpdateDataFile(CustomerList&);


int
main()
{
	cout << "Hello, World!" << endl;
	exit(EXIT_SUCCESS);
}


void
LoadCustomers(ifstream& f, CustomerList& customer)
{
	return;
}


int
selectMenu()
{
	return (0);
}


void 
PlaceOrder(CustomerList& order)
{
	return;
}


void
UpdateOrder(CustomerList& order)
{
	return;
}


void
PrintOrders(CustomerList& orders)
{
	return;
}


void
CheckoutOrders(CustomerList& orders)
{
	return;
}


void
UpdateDataFile(CustomerList& file)
{
	return;
}

void
CancelOrder(CustomerList&)
{
	return;
}
