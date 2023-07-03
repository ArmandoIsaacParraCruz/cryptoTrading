#pragma once
#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
    public:
        MerkelMain() = default;
        /** Call this to start the simulation*/
        void init();
    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
        void printInvalidOption();
        double computeAveragePrice(std::vector<OrderBookEntry>& entries);
        double computeLowPrice(std::vector<OrderBookEntry>& entries);
        double computeHighPrice(std::vector<OrderBookEntry>& entries);
        double computePriceSpread(std::vector<OrderBookEntry>& entries);
        std::vector<OrderBookEntry> orders;
};