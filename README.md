# Orderbook
Orderbook is a C++ implementation of a limit order book, the core data structure used in financial markets to match buy and sell orders in real time. The project models how bids and asks interact and provides a foundation for building trading engines, matching engines, or market simulators. It is designed as both a functional system and a learning tool for understanding market microstructure.


## Features
- Written in C++ with a focus on performance and clarity
- Implements a limit order book with bid and ask matching logic
- Supports multiple order types
- Demonstrates core concepts used in real trading systems
- Suitable as a base for simulations or further extensions


## Tech Stack
- Language: C++
- Project Structure: Header and source files
- Tooling: Compatible with standard C++ compilers and IDEs


## How It Works
The system maintains an in memory representation of bids and asks and processes incoming orders by matching them based on price and order priority. As orders are added and matched, the state of the order book updates to reflect current market conditions. This mirrors the fundamental mechanics used by real world trading venues.


## License
This project is licensed under the MIT License. See the LICENSE file for details.


## Setup and Installation
### Clone the repository

```bash
git clone https://github.com/salehyahyaa/Orderbook.git
cd Orderbook
