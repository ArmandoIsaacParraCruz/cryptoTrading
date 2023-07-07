#include <iostream> 
#include <vector> 
#include <string>
#include <fstream>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CropPriceData.h"

std::vector<std::string> tokenise(std::string csvLine, char separator) 
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
} 


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
} 


int main(void)
{
    std::string csvFilenName{"crop_price_data.csv"};
    std::ifstream csvFile{csvFilenName};
    std::string line;
    if(csvFile.is_open()) {
        std::cout << "Opend file" << csvFilenName << std::endl;
        std::vector<CropPriceData> data = processFile(csvFile);

        for(CropPriceData &temp: data) {
            std::cout << temp.districtName << ",";
            std::cout << temp.cropName << ",";
            std::cout << temp.marketName << ",";
            std::cout << temp.date << ",";
            std::cout << temp.price << std::endl;
        }

    } else {
        std::cout << "Problem opening file " << csvFilenName << std::endl;
    }
    csvFile.close();
    /*MerkelMain app{};
    app.init();*/
    return 0;
}


