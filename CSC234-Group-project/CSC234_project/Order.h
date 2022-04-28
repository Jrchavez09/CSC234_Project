#ifndef Order_H
#define Order_H

#include <ostream>
#include <string>
#include <cstdbool>

using std::string;
using std::ostream;

class Order
{
	friend ostream& operator<<(ostream& os, const Order& order);

	private:
		string bookTitle;
		double unitPrice;
		int number;

	public:
		Order();
		Order(string _bookTitle, double _unitPrice, int _number);
		bool checkTitle(string name);
		double CalculateCost();
		void setNumber(int _number);
		string getTitle();
		double getPrice();
		int getNumber();

		bool operator==(const Order& other) const;
		bool operator!=(const Order& other) const;
};

#endif // !Order_H

