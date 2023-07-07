#include <iostream> 
#include <vector> 
#include <string>
#include <fstream>
#include "MerkelMain.h"
#include "OrderBookEntry.h"

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
 


int main(void)
{
    std::string csvFilenName{"crop_price_data.csv"};
    std::ifstream csvFile{csvFilenName};
    std::string line;
    if(csvFile.is_open()) {
        std::cout << "Opend file" << csvFilenName << std::endl;
    } else {
        std::cout << "Problem opening file " << csvFilenName << std::endl;
    }
    std::getline(csvFile,line); 
    std::cout<<"Read line "<<line<<std::endl;
    csvFile.close();
    /*MerkelMain app{};
    app.init();*/
    return 0;
}


