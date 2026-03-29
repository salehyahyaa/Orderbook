# Orderbook
Orderbook is a C++ implementation of a limit order book, the core data structure used in financial markets to match buy and sell orders in real time. The project models how bids and asks interact and provides a foundation for building trading engines, matching engines, or market simulators. It is designed as both a functional system and a learning tool for understanding market microstructure.


## Features
- Price-time priority matching (FIFO within each price level)
- Separate bid/ask books with efficient best-price access
- Order lifecycle operations:
  - **Add** orders
  - **Cancel** orders
  - **Modify** orders (cancel + re-add with original order type)
- Supported order types:
  - **GoodTillCancel (GTC)**
  - **GoodForDay (GFD)** (auto-pruned at end-of-day)
  - **FillAndKill (FAK)** (cancels remainder after matching attempt)
  - **FillOrKill (FOK)** (must fully fill immediately or is rejected)
  - **Market** (converted internally to a priced order based on book state)
- Threaded pruning of **GoodForDay** orders (background thread)
- Basic “level info” snapshot API (bids/asks aggregated by price)


## Project Structure
- `Orderbook.h` / `Orderbook.cpp` — core order book implementation
- `Order.h` — order model (quantity tracking, fill logic)
- `OrderType.h`, `Side.h` — enums for order type and side
- `Trade.h`, `TradeInfo.h` — trade output structures
- `OrderbookTest/` — Visual Studio test project


## Tech Stack
- Language: C++
- Project Structure: Header and source files
- Tooling: Compatible with standard C++ compilers and IDEs


## Setup 
This repository includes the following project files:
- `Orderbook.sln`
- `Orderbook.vcxproj`
- `OrderbookTest/OrderbookTest.vcxproj`

## License
This project is licensed under the MIT License. See the LICENSE file for details.


### Clone the repository
```bash
git clone https://github.com/salehyahyaa/LimitOrderMatchingSystem.git
cd Orderbook