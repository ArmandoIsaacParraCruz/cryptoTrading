#pragma once 

#include <iostream>
#include <vector>  
#include <string>  

enum class OrderBookType { /** An enumeration representing the types of order book entries. */
    bid,        /** Represents a bid order. */
    ask,        /** Represents an ask order. */
    asksale,    /** Represents a sale of an ask order. */
    bidsale,    /** Represents a sale of a bid order. */
    unknown     /** Represents an unknown or invalid type. */
};

class OrderBookEntry
{
public:
    double amount;       /** The amount of the cryptocurrency in the order book entry. */
    double price;        /** The price of the cryptocurrency in the order book entry. */
    std::string timestamp; /** The timestamp of the order book entry. */
    std::string product;   /** The product (e.g., BTC/USD) of the order book entry. */
    OrderBookType orderType; /** The type of the order book entry (bid, ask, etc.). */
    std::string username; /** The username associated with the order book entry (default is "dataset"). */

    /** Constructor to create an instance of the OrderBookEntry class. */
    OrderBookEntry(double _price, double _amount, std::string _timestamp,
                   std::string _product, OrderBookType _orderType, std::string username = "dataset");
    
    /** Static method to convert a string representation to an OrderBookType enum value. */
    static OrderBookType stringToOrderBookType(const std::string& s);
    /** Static method to compare two OrderBookEntry objects based on their timestamps. */
    static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2);
    /** Static method to compare two OrderBookEntry objects based on their prices in ascending order. */
    static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2);
    /** Static method to compare two OrderBookEntry objects based on their prices in descending order. */
    static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2);
    
};
