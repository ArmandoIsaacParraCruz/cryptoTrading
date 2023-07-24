#pragma once 

#include "../OrderBookEntry/OrderBookEntry.h" /** Include the OrderBookEntry.h header file from the "OrderBookEntry" directory. */
#include <fstream> 
#include <vector> 
#include <string>  

class CSVReader
{
public:
    CSVReader(); /** Constructor for the CSVReader class. */

    /** Static method to read CSV data from the specified file and return a vector of OrderBookEntry objects. */
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    
    /** Static method to tokenize a CSV line based on the given separator character and return a vector of strings. */
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    

    /** Static method to convert strings to an OrderBookEntry object. */
    static OrderBookEntry stringToOrderBookEntry(std::string priceString,
                                                 std::string amountString,
                                                 std::string timestamp,
                                                 std::string product,
                                                 OrderBookType orderBookType);
    

private:
    /** Static method to convert a vector of strings to an OrderBookEntry object. */
    static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> tokens);
    
};
