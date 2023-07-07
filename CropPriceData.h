#pragma once
#include <iostream> 
#include <vector> 
#include <string>
#include <fstream>

class CropPriceData
{
    public:
        CropPriceData(std::string _districName, std::string _cropName, std::string _marketName, std::string _date, double _price);
        std::string districName;
        std::string cropName;
        std::string marketName;
        std::string date;
        double price;
};