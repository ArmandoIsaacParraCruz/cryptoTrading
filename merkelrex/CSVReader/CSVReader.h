#pragma once
#include "../OrderBookEntry/OrderBookEntry.h"
#include <fstream>
#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringToOrderBookEntry(std::string priceString,
                                                    std::string amountString,
                                                    std::string timestamp,
                                                    std::string product,
                                                    OrderBookType orderBookType);
    private:
        static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> tokens);
};