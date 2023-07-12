#include "OrderBook.h"

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnowProducts()
{
    std::vector<std::string> products;
    std::map<std::string,bool> productMap;

    for(OrderBookEntry& e: orders) {
        productMap[e.product] = true;
    }
    
    for(auto const& e: productMap) {
        products.push_back(e.first);
    }
    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    for(OrderBookEntry& e: orders) {
        if(e.orderType == type && e.product == product && e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string nextTimestamp = "";
    for(OrderBookEntry& e: orders) {
        if(e.timestamp > timestamp) {
            nextTimestamp = e.timestamp;
            break;
        }
    }

    if(nextTimestamp == "") {
        nextTimestamp = getEarliestTime();
    }

    return nextTimestamp;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
    double max = orders[0].price;
    for(OrderBookEntry& e: orders) {
        if(e.price > max) {
            max = e.price;
        }
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
    double min = orders[0].price;
    for(OrderBookEntry& e: orders) {
        if(e.price < min) {
            min = e.price;
        }
    }
    return min;
}



double OrderBook::getSpreadPrice(std::vector<OrderBookEntry> &orders)
{
    double highPrice = getHighPrice(orders);
    double lowPrice = getLowPrice(orders);
    return highPrice - lowPrice;
}

/**returns the average of the price in the sent set */
double OrderBook::getAveragePrice(std::vector<OrderBookEntry> &orders)
{
    double sum = 0;
    for(OrderBookEntry& e: orders) {
        sum += e.price;
    }
    return sum/orders.size();
}

/**returns the standard deviation of the price in the sent set */
double OrderBook::getStandardDeviation(std::vector<OrderBookEntry> &orders)
{
    double standartDeviation, 
            sum = 0, 
            average = getAveragePrice(orders);

    for(OrderBookEntry& e: orders) {
        sum += std::pow(e.price - average, 2); 
    }

    sum /= orders.size();
    standartDeviation = std::sqrt(sum); 
    return standartDeviation;
}
