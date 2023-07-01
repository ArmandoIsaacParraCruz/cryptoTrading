#include<iostream> 
#include<vector> 
#include<string>

enum class OrderBookType{bid,ask};

class OrderBookEntry
{
    public:
        double amount;
        double price;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
        OrderBookEntry(double _amount, double _price, std::string _timestamp,
                        std::string _product, OrderBookType _orderType);
};

OrderBookEntry::OrderBookEntry(double _amount, double _price, std::string _timestamp, 
                                std::string _product, OrderBookType _orderType):
    amount(_amount), price(_price), timestamp(_timestamp), product(_product), orderType(_orderType)
{

}



void printMenu()
{
    std::cout << "Typein1-6" << std::endl;
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
}

int getUserOption()
{
    int userOption;
    std::cin >> userOption;
    return userOption;
}

void printHelp()
{
    std::cout << "Help-choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}

void printExchangeStats()
{
    std::cout << "Market looks good. It is a good time to invest money" << std::endl;
}

void placeAnAsk()
{
    std::cout << "Enter the amount to make an offer" << std::endl;
}

void placeABid()
{
    std::cout << "Enter the amount to make a bid" << std::endl;
}

void printWallet()
{
    std::cout << "You don't have money :(" << std::endl;
}

void goAhead()
{
    std::cout << "Going to the nest time frame..." << std::endl;
}

void printInvalidOption()
{
    std::cout << "Invalid input, enter a value again" << std::endl;
}

void processUserOption(int userOption)
{
    std::cout << "Your choice: " << userOption << std::endl;
    if (userOption == 1) {
        printHelp();
    }
    else if (userOption == 2)
    {
        printExchangeStats();
    }
    else if (userOption == 3)
    {
        placeAnAsk();
    }
    else if (userOption == 4)
    {
        placeABid();
    }
    else if (userOption == 5)
    {
        printWallet();
    }
    else if (userOption == 6)
    {
        goAhead();
    }
    else
    {
        printInvalidOption();
    }
}

double computeAveragePrice(std::vector<OrderBookEntry>& entries)
{
    double sum = 0;
    for(size_t i = 0; i < entries.size(); ++i)
    {
        sum += entries[i].price;
    }

    return sum/entries.size();
}

double computeLowPrice(std::vector<OrderBookEntry>& entries)
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

double computeHighPrice(std::vector<OrderBookEntry>& entries)
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

double computePriceSpread(std::vector<OrderBookEntry>& entries)
{
    double highPrice = computeHighPrice(entries);
    double lowPrice = computeLowPrice(entries);
    return highPrice - lowPrice;
}

/**
OrderBookEntry::OrderBookEntry(double _amount, double _price, std::string _timestamp, 
                                std::string _product, OrderBookType _orderType):
    amount(_amount), price(_price), timestamp(_timestamp), product(_product), orderType(_orderType)
{

}
*/

int main(void)
{
    int userOption;
    
    OrderBookEntry obe1{7.44564869, 0.5, "2020/03/17 17:01:24.884492",
                        "ETH/BTC", OrderBookType::bid};
    OrderBookEntry obe2{3.467434, 0.3, "2020/03/17 17:01:24.884492",
                        "ETH/BTC", OrderBookType::ask};
    OrderBookEntry obe3{6.85567013, 0.4, "2020/03/17 17:01:24.884492",
                        "ETH/BTC", OrderBookType::bid};
    
    std::vector<OrderBookEntry> orders;
    orders.push_back(obe1);
    orders.push_back(obe2);
    orders.push_back(obe3);
    
    for(OrderBookEntry& order: orders)
    {
        std::cout << order.timestamp << ",";
        std::cout << order.product << ",";
        if(order.orderType == OrderBookType::bid) {
            std::cout << "bid" << ",";
        } else {
            std::cout << "ask" << ",";
        }
        std::cout << order.price << ",";
        std::cout << order.amount << std::endl;
    }

    std::cout << "Average: " << computeAveragePrice(orders) << std::endl;
    std::cout << "Low Price: " << computeLowPrice(orders) << std::endl;
    std::cout << "High Price: " << computeHighPrice(orders) << std::endl;
    std::cout << "Price Spread: " << computePriceSpread(orders) << std::endl;
    
    while(true)
    {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption);    
    }
    return 0;
}


