#include "MerkelMain.h"


void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
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
    std::cout << "=======================" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
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
    for(std::string const p: orderBook.getKnowProducts()) {
        std::cout << "Products: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Ask seen: " <<entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
        std::cout << "Average ask: " << OrderBook::getAveragePrice(entries) << std::endl;
        std::cout << "Spread ask: " << OrderBook::getSpreadPrice(entries) << std::endl;
        std::cout << "Standart Devation ask: " << OrderBook::getStandardDeviation(entries) << std::endl;
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
    currentTime = orderBook.getNextTime(currentTime);
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
    } else if (userOption == 2)
    {
        printMarketStats();
    } else if (userOption == 3)
    {
        enterOffer();
    } else if (userOption == 4)
    {
        enterBid();
    } else if (userOption == 5)
    {
        printWallet();
    } else if (userOption == 6) {
        gotoNextTimeFrame();
    } else {
        printInvalidOption();
    }
}

