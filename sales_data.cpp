#include <iostream>
#include <ostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data data1, data2;
    cout << "Enter the price of the 2 books respectively:" << endl;
    double price1=0.0, price2=0.0;
    cin >> price1 >> price2;
    cin >> data1.bookNo >> data1.units_sold >> price1;
    data1.revenue = price1 * data1.units_sold;
    cin >> data2.bookNo >> data2.units_sold >> price2;
    data2.revenue = price2 * data2.units_sold;
    if (data1.bookNo == data2.bookNo)
    {
        unsigned total_sold = data1.units_sold + data2.units_sold;
        double total_revenue = data1.revenue + data2.revenue;
        return total_revenue/total_sold;
    }else
    {
        cerr << "Data must have the same book number" << endl;
        return -1;
    }
}
