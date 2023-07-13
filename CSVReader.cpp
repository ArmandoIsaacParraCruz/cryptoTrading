#include "CSVReader.h"

CSVReader::CSVReader()
{
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName)
{
    std::ifstream csvFile{csvFileName};
    std::vector<OrderBookEntry> entries;
    if(csvFile.is_open()) {
        std::cout << "Opend file" << csvFileName << std::endl;
        std::string line;
        while(getline(csvFile, line))
        {
            std::vector<std::string> tokens = CSVReader::tokenise(line, ',');
            entries.push_back(CSVReader::stringToOrderBookEntry(tokens));
        }
    } else {
        std::cout << "Problem opening file " << csvFileName << std::endl;
    }
    csvFile.close();
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens; 
    signed int start, end; 
    start = csvLine.find_first_not_of(separator, 0); 
    do { 
        end = csvLine.find_first_of(separator, start); 
        if(start == csvLine.length() || start == end) { 
            break; 
        } 

        if(end >= 0) { 
            tokens.push_back(csvLine.substr(start, end - start)); 
        } else { 
            tokens.push_back(csvLine.substr(start, csvLine.length() - start)); 
        } 

        start = end + 1; 
    }while(end != std::string::npos); 
    return tokens; 
    return tokens;
}

OrderBookEntry CSVReader::stringToOrderBookEntry(std::string priceString, std::string amountString, std::string timestamp, std::string product, OrderBookType orderBookType)
{
    double price, amount;
    try {
        price = std::stod(priceString);
        amount = std::stod(amountString);
    } catch(const std::exception& e) {
        std::cout << "it isn't a double" << priceString << std::endl;
        std::cout << "it isn't a double" << amountString << std::endl;
        throw;
    }

    OrderBookEntry obe{price, amount, timestamp, product, orderBookType};
    return obe;
}

OrderBookEntry CSVReader::stringToOrderBookEntry(std::vector<std::string> tokens)
{
    double price, amount; const uint8_t correctSizeOfToken = 5;
    if(tokens.size() != correctSizeOfToken) {
        std::cout << "Corrupted line" << std::endl;
        throw std::exception{};
    }

    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch(const std::exception& e) {
        std::cout << "it isn't a double" << tokens[3] << std::endl;
        std::cout << "it isn't a double" << tokens[4] << std::endl;
        throw;
    }

    OrderBookEntry obe{price, amount, tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
}
