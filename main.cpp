#include <iostream> 
#include <vector> 
#include <string>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"


/*
std::vector<CropPriceData> processFile(std::ifstream &csvFile) 
{
    std::vector<CropPriceData> data;
    std::string line;
    while(getline(csvFile, line))
    {
        double price = 0;
        std::vector<std::string> tokens = tokenise(line, ',');
        if(tokens.size() != 5) {
            std::cout << "Invalid line" << std::endl;
            continue;
        }
        try {
            price = std::stod(tokens.at(4));

        } catch (const std::exception& e) {
            continue;
        }
        
        data.push_back(CropPriceData {tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), price});
    }
    return data; 
} */


int main(void)
{
    MerkelMain app{};
    app.init();
    return 0;
}


