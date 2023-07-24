#pragma once 

#include <vector>   
#include <string>   
#include <iostream> 
#include <limits>  
#include <algorithm> 
#include "../OrderBookEntry/OrderBookEntry.h" /** Include the OrderBookEntry.h header file from the "OrderBookEntry" directory. */
#include "../CSVReader/CSVReader.h" /** Include the CSVReader.h header file from the "CSVReader" directory. */
#include "../OrderBook/OrderBook.h" /** Include the OrderBook.h header file from the "OrderBook" directory. */
#include "../Wallet/Wallet.h" /** Include the Wallet.h header file from the "Wallet" directory. */

class MerkelMain
{
public:
    /** Default constructor for the MerkelMain class. */
    MerkelMain() = default;

    /** Call this to start the simulation */
    void init(); /** Declaration of the "init" method. It is a public member function that starts the simulation. */

private:
    /** Declaration of an instance of the OrderBook class named "orderBook".
        It is initialized with data from the CSV file "20200317.csv" in the "MerkelMain" directory. */
    OrderBook orderBook{"../MerkelMain/20200317.csv"};
   
    /** Declaration of a string variable to store the current time during the simulation. */
    std::string currentTime;
    
    /** Declaration of an instance of the Wallet class named "wallet".
        It is initialized using the default constructor. */
    Wallet wallet{};
   

    // Declaration of private member functions used within the class for various functionalities.

    /** Function to print the menu options during the simulation. */
    void printMenu();
    
    /** Function to print help information during the simulation. */
    void printHelp();

    /** Function to print market statistics during the simulation. */
    void printMarketStats();

    /** Function to enter an ask order during the simulation. */
    void enterAsk();

    /** Function to enter a bid order during the simulation. */
    void enterBid();

    /** Function to print the contents of the wallet during the simulation. */
    void printWallet();

    /** Function to move to the next time frame during the simulation. */
    void gotoNextTimeFrame();

    /** Function to get the user's option during the simulation. */
    int getUserOption();

    /** Function to process the user's chosen option during the simulation. */
    void processUserOption(int userOption);

    /** Function to print a message for an invalid user option during the simulation. */
    void printInvalidOption();
};
