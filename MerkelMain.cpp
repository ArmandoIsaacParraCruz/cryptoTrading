#include "MerkelMain.h"


void MerkelMain::init()
{
    loadOrderBook();
    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::loadOrderBook()
{
    orders = CSVReader::readCSV("20200317.csv");
    std::cout << "MerkelMain::loadOrderBook read " << orders.size() << " orders" << std::endl;
}


void MerkelMain::printMenu()
{
    std::cout << "Typein1-6" << std::endl;
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
}

int MerkelMain::getUserOption()
{
    int userOption;
    std::cin >> userOption;
    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help-choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}

void MerkelMain::printMarketStats()
{
     for(OrderBookEntry& order: orders)
    {
        std::cout << order.timestamp << ",";
        std::cout << order.product << ",";
        if(order.orderType == OrderBookType::bid) {
            std::cout << "bid" << ",";
        } else if(order.orderType == OrderBookType::ask){
            std::cout << "ask" << ","; 
        } else {
            std::cout << "unknown" << ","; 
        }
        std::cout << order.price << ",";
        std::cout << order.amount << std::endl;
    }
}

void MerkelMain::enterOffer()
{
    std::cout << "Enter the amount to make an offer" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Enter the amount to make a bid" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "You don't have money :(" << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to the nest time frame..." << std::endl;
}

void MerkelMain::printInvalidOption()
{
    std::cout << "Invalid input, enter a value again" << std::endl;
}

void MerkelMain::processUserOption(int userOption)
{
    std::cout << "Your choice: " << userOption << std::endl;
    if (userOption == 1) {
        printHelp();
    }
    else if (userOption == 2)
    {
        printMarketStats();
    }
    else if (userOption == 3)
    {
        enterOffer();
    }
    else if (userOption == 4)
    {
        enterBid();
    }
    else if (userOption == 5)
    {
        printWallet();
    }
    else if (userOption == 6)
    {
        gotoNextTimeFrame();
    }
    else
    {
        printInvalidOption();
    }
}

double MerkelMain::computeAveragePrice(std::vector<OrderBookEntry>& entries)
{
    double sum = 0;
    for(size_t i = 0; i < entries.size(); ++i)
    {
        sum += entries[i].price;
    }

    return sum/entries.size();
}

double MerkelMain::computeLowPrice(std::vector<OrderBookEntry>& entries)
{
    double lowPrice = entries[0].price;
    for(size_t i = 1; i < entries.size(); ++i)
    {
        if(entries[i].price < lowPrice)
        {
            lowPrice = entries[i].price;
        }
    }
    return lowPrice;
}

double MerkelMain::computeHighPrice(std::vector<OrderBookEntry>& entries)
{
    double highPrice = entries[0].price;
    for(size_t i = 1; i < entries.size(); ++i)
    {
        if(entries[i].price > highPrice)
        {
            highPrice = entries[i].price;
        }
    }
    return highPrice;
}

double MerkelMain::computePriceSpread(std::vector<OrderBookEntry>& entries)
{
    double highPrice = computeHighPrice(entries);
    double lowPrice = computeLowPrice(entries);
    return highPrice - lowPrice;
}