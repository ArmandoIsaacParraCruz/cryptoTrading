#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class OrderBookType{bid, ask, asksale, bidsale,unknown};

class OrderBookEntry
{
    public:
        double amount;
        double price;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
        OrderBookEntry(double _price, double _amount, std::string _timestamp,
                        std::string _product, OrderBookType _orderType, std::string username = "dataset");
        static OrderBookType stringToOrderBookType(const std::string& s);
        static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2);
        static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2);
        static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2);
        std::string username;
};