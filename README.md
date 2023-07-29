# Crypto Exchange Simulator

The Crypto Exchange Simulator is a command-line application that simulates a crypto exchange's functionality. It was created with the guide of the course "Object Oriented Programming" 
of the University of London, Goldsmiths, Coursera.

## Getting Started

### Prerequisites

- C++ compiler that supports C++11 or later
- Standard Template Library (STL)
- Access to a command-line interface or terminal

### Installation

1. Clone the repository to your local machine:

# Replace 'your-username' with your actual GitHub username
git clone https://github.com/your-username/cryptosim.git


2. Navigate to the project directory:

cd merkelrex
cd scr


### Usage

1. Compile the source code using the C++ compiler:
g++ -std=c++11 main.cpp ../OrderBookEntry/OrderBookEntry.cpp ../OrderBook/OrderBook.cpp ../Wallet/Wallet.cpp ../CSVReader/CSVReader.cpp ../MerkelMain/MerkelMain.cpp -o cryptosim


2. Run the application:
./cryptosim


3. The application will display a menu with various options. Follow the on-screen instructions to interact with the order book and virtual wallet.

## Features

- View market statistics for known products, including the number of asks, maximum ask price, minimum ask price, average ask price, spread ask price, and standard deviation of ask prices.
- Place an ask order by specifying the amount, product (currency pair), and price.
- Place a bid order by specifying the amount, product (currency pair), and price.
- Print the contents of the virtual wallet, showing the available balances for each currency.
- Advance to the next time frame to process matched bids and asks and update the wallet balances accordingly.

## Classes

The Crypto Exchange Simulator is structured using the following classes:

- `MerkelMain`: Represents the main application that manages the order book and virtual wallet. It provides a text-based menu for user interaction.
- `OrderBook`: Manages the order book, containing a list of open orders. It matches bids with asks and processes sales accordingly.
- `Wallet`: Represents a virtual wallet that holds balances for various currencies. It allows inserting and removing currencies and checks for sufficient funds during order placement.
- `CSVReader`: A utility class for reading CSV files and converting data into `OrderBookEntry` instances.

## License

The Crypto Exchange Simulator is licensed under the [MIT License](LICENSE).

**Note:** The above README provides a basic structure and information about the Crypto Exchange Simulator project.

