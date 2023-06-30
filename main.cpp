#include <iostream>

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



int main(void)
{
    int userOption;
    while(true)
    {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption);    
    }
    return 0;
}