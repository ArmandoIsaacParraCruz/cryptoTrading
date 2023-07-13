#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "OrderBook.h"


class MerkelMain
{
    public:
        MerkelMain() = default;
        /** Call this to start the simulation*/
        void init();
    private:
        OrderBook orderBook{"20200317.csv"};
        std::string currentTime;

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