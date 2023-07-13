#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class OrderBookType{bid, ask, sale,unknown};

class OrderBookEntry
{
    public:
        double amount;
        double price;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
        OrderBookEntry(double _amount, double _price, std::string _timestamp,
                        std::string _product, OrderBookType _orderType);
        static OrderBookType stringToOrderBookType(const std::string& s);
        static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2);
        static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2);
        static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2);
};