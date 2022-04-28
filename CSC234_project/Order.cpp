#include <ostream>
#include <string>
#include <cstdbool>
#include <iomanip>

#include "Order.h"

using namespace std;

ostream& operator<<(ostream& os, const Order& order)
{
	os << fixed << showpoint << setprecision(2);
	os << setw(13) << left << "Title: "
	   << setw(37) << right << order.bookTitle << endl;
	os << setw(13) << left << "Unit Price: $ "
	   << setw(37) << right << order.unitPrice << endl;
	os << setw(13) << left << "Number: "
	   << setw(37) << right << order.number << endl;

	return (os);
}

Order::Order() : bookTitle("default"), unitPrice(0.0), number(0) { }

Order::Order(string _bookTitle, double _unitPrice, int _number) :
	bookTitle(_bookTitle),
	unitPrice(_unitPrice),
	number(_number) { }


bool
Order::checkTitle(string name)
{
	return (bookTitle == name);
}


double
Order::CalculateCost()
{ 
	return (unitPrice * number);
}
		

void
Order::setNumber(int _number)
{ 
	number = _number;
}
		

string
Order::getTitle()
{ 
	return (bookTitle);
}
		

double
Order::getPrice()
{ 
	return (unitPrice);
}
		

int
Order::getNumber()
{ 
	return (number);
}


bool 
Order::operator==(const Order& other) const
{
	return (bookTitle == other.bookTitle && unitPrice == other.unitPrice
		&& number == other.number);
}


bool
Order::operator!=(const Order& other) const
{
	return (bookTitle != other.bookTitle || unitPrice != other.unitPrice
		|| number != other.number);
}