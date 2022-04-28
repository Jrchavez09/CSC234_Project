#include <cstdbool>
#include <fstream>


#include "OrderList.h"


ostream& operator<<(ostream& osObject, const OrderList& orders)
{
        orders.print();
        return osObject;
}


void
OrderList::AddOrder(Order& _order)
{
        insertLast(_order);
}


void
OrderList::UpdateOrder(string _title, int _number)
{
        bool found = false;
        nodeType<Order>* location;

        
        SearchOrderList(_title, found, location);

        if (found) {
                location->info.setNumber(_number);
                cout << "The order is updated." << endl;
        } else {
                cout << "Order is not found." << endl;
        }
        return;
}


void OrderList::CancelOrder(string title)
{
        bool found = false;
        nodeType<Order>* current = first;
        

        SearchOrderList(title, found, current);
        deleteNode(current->info);

}


double
OrderList::CalculateSubtotal()
{
        nodeType<Order>* current;
        current = first;
        double subtotal = 0.0;
        

        while (current != nullptr) {
                subtotal += (current->info.CalculateCost());
                current = current->link;
        }
        return subtotal;
}


void
OrderList::UpdateDataFile(ofstream& file)
{
        nodeType<Order>* current;
        current = first;
        

        while (current != nullptr) {
                file << current->info.getTitle() << endl;
                file << current->info.getPrice() << endl;
                file << current->info.getNumber() << endl;
                current = current->link;
        }
        return;
}


void
OrderList::SearchOrderList(string title, bool& found,
                nodeType<Order>*& current) const
{
        found = false;
        current = first;
        

        while (current != nullptr && !found) {
                if (current->info.checkTitle(title)) {
                        found = true;
                } else {
                        current = current->link;
                }
        }
        return;
}

