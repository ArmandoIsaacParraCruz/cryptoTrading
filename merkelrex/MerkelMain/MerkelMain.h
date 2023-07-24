#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include "../OrderBookEntry/OrderBookEntry.h"
#include "../CSVReader/CSVReader.h"
#include "../OrderBook/OrderBook.h" 
#include "../Wallet/Wallet.h"

class MerkelMain
{
    public:
        MerkelMain() = default;
        /** Call this to start the simulation*/
        void init();
    private:
        OrderBook orderBook{"../MerkelMain/20200317.csv"};
        std::string currentTime;
        Wallet wallet{};
        
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
        void printInvalidOption();
};