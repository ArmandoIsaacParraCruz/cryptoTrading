#pragma once
#include "OrderBookEntry.h"
#include <fstream>
#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    private:
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> tokens);
};