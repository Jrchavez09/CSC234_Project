#ifndef Order_H
#define Order_H

#include <ostream>
#include <string>
#include <cstdbool>
#include <iomanip>

using std::string;
using std::ostream;

class Order
{
	friend ostream& operator<<(ostream& os, const Order& order)
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

	private:
		string bookTitle;
		double unitPrice;
		int number;

	public:
		Order() : bookTitle("default"), unitPrice(0.0), number(0) { }
		Order(string _bookTitle, double _unitPrice, int _number) :
			bookTitle(_bookTitle),
			unitPrice(_unitPrice),
			number(_number) { }

		bool checkTitle(string name) { return (bookTitle == name); }
		double calculateCost() { return (unitPrice * number); }
		void setNumber(int _number) { number = _number; }
		string getTitle() { return (bookTitle); }
		double getPrice() { return (unitPrice); }
		int getNumber() { return (number); }

		bool 
		operator==(const Order& other) const
		{
			return (bookTitle == other.bookTitle && unitPrice == other.unitPrice
				&& number == other.number);
		}


		bool
		operator!=(const Order& other) const
		{
			return (bookTitle != other.bookTitle || unitPrice != other.unitPrice
				|| number != other.number);
		}
};

#endif // !Order_H

