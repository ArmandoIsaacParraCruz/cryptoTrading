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
    std::cout << "===========================================" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
}

int MerkelMain::getUserOption()
{
    int userOption; 
    std::string line;
    std::getline(std::cin, line);
    try {
            userOption = std::stoi(line);
    } catch(const std::exception& e) {
            std::cout << "'"<< line <<"'" << " is not a valid option" << std::endl;
    }   
    
   
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
        std::cout << "===========================================" << std::endl;
    }
}

void MerkelMain::enterAsk()
{
    std::cout << "Enter the amount to make an ask: product, price, eg, ETH/BTC,200,0.5" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3) {
        std::cout << "An input error occurred" << std::endl;
    } else {
        std::cout << "You typed " << input << std::endl;
        try {
            OrderBookEntry obe = CSVReader::stringToOrderBookEntry(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
            orderBook.insertOrder(obe);
        } catch(const std::exception& e) {
            std::cout << "The 'ask' is invalid" << std::endl;
        }   
    }
}

void MerkelMain::enterBid()
{
    std::cout << "Enter the amount to make a bid: product, price, eg, ETH/BTC,200,0.5" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3) {
        std::cout << "An input error occurred" << std::endl;
    } else {
        std::cout << "You typed " << input << std::endl;
        try {
            OrderBookEntry obe = CSVReader::stringToOrderBookEntry(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
            orderBook.insertOrder(obe);
        } catch(const std::exception& e) {
            std::cout << "The 'bid' is invalid" << std::endl;
        }
    }   
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

    switch (userOption)
    {
        case 1:
            printHelp();
        break;

        case 2:
            printMarketStats();
        break;

        case 3:
           enterAsk();
        break;

        case 4:
             enterBid();
        break;

        case 5:
           printWallet();
        break;

        case 6:
            gotoNextTimeFrame();
        break;
        
        default:
            printInvalidOption();
        break;
    }
}

