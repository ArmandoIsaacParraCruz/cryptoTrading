#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _amount, double _price, std::string _timestamp, 
                                std::string _product, OrderBookType _orderType):
    amount(_amount), price(_price), timestamp(_timestamp), product(_product), orderType(_orderType)
{

}