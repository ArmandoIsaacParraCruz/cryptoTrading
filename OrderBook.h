#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <map>

class OrderBook
{
    public:
        /**construct, reading a csv data file*/
        OrderBook(std::string filename);
        /**return vector of aall know products in the dataset*/
        std::vector<std::string> getKnowProducts();
        /**return vector of Orders according to the sent filters*/
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                                std::string product,
                                                std::string timestamp);
        /**return the price of the highest bid in the sent set*/
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /**return the price of the lowest bit in the sent set*/
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
        /**return the average price bid in the sent set*/
        static double getAveragePrice(std::vector<OrderBookEntry>& orders);
        /**return the spread price bit in the sent set*/
        static double getSpreadPrice(std::vector<OrderBookEntry>& orders);

    private:
        std::vector<OrderBookEntry> orders;
};