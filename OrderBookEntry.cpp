#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _amount, double _price, std::string _timestamp, 
                                std::string _product, OrderBookType _orderType):
    amount(_amount), price(_price), timestamp(_timestamp), product(_product), orderType(_orderType)
{

}

OrderBookType OrderBookEntry::stringToOrderBookType(const std::string &s)
{
    if(s == "ask") {
        return OrderBookType::ask;
    } else if(s == "bid") {
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}
