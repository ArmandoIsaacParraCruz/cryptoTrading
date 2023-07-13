#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

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
        
        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);
        void insertOrder(OrderBookEntry& order);
        /**returns the earliest time in the orderbook*/
        std::string getEarliestTime();
        /**returns tthe nest time after the sent in the orderbook*/
        std::string getNextTime(std::string timestamp);
        /**returns the price of the highest bid in the sent set*/
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /**returns the price of the lowest bit in the sent set*/
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
        /**returns the average price bid in the sent set*/
        static double getAveragePrice(std::vector<OrderBookEntry>& orders);
        /**returns the spread price bit in the sent set*/
        static double getSpreadPrice(std::vector<OrderBookEntry>& orders);
        /**returns the standar deviation of the price in the sent set*/
        static double getStandardDeviation(std::vector<OrderBookEntry>& orders);

    private:
        std::vector<OrderBookEntry> orders;
};