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

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);

    std::vector<OrderBookEntry> sales;

    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);
    for(OrderBookEntry& ask: asks) {
        for(OrderBookEntry& bid: bids) {
            if(bid.price >= ask.price) {
                OrderBookEntry sale{ask.price, 0, timestamp, product, OrderBookType::sale};
                if(bid.amount == ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                } else if(bid.amount > ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                } else if(bid.amount < ask.amount) {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }
    
    return sales;
}

void OrderBook::insertOrder(OrderBookEntry &order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
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
