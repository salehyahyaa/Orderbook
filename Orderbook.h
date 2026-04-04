#pramga once 

#include <map> //dict in py
#include <unorderd_map>
#include <thread>
#include <condition_variable>
#include <mutex>

#include "Usings.h"
#include "Order.h"
#include "OrderModify.h"
#include "OrderbookLevelInfos.h"
#include "Trade.h"
/*
An orderbook is a catelog that maintains all active buy and sell orders for a financial instrument, organized by price and time priority
*/

class Orderbook {
    private:                //when storing orders we'll use a map(DSA) to represent bids && asks, bids sorted in ascneding order(best bids), asks sorted in desencding order(best ask), we will have O(1) easy access based on orderId
    
      struct OrderEntry {
        OrderPointer order_{ nullptr };
        OrderPointers::iterator location_;
      };

      std::map<Price, OrderPointers, std::greater<Price>> bids_;
      std::map<Price, OrderPointers, std::less<Price>> asks_;


  
  };

