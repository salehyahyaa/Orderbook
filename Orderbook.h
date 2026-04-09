#pramga once 

#include <map> //dict in py
#include <unordered_map>
#include <thread>
#include <condition_variable>
#include <mutex>

#include "Usings.h"
#include "Order.h"
#include "OrderModify.h"
#include "OrderbookLevelInfos.h"
#include "Trade.h"
/*
An orderbook is a catelog that maintains all active buy and sell orders for a financial instrument, organized by price, time priority
*/


class Orderbook {
    private:                                                        //when storing bids &&asks we'll use a map, bids sorted in ascneding order(best bids), asks sorted in desencding order(best ask), we will have O(1) easy access based on orderId
    
      struct OrderEntry {                                           //represents an order and its location in the orderbook
        OrderPointer order_{ nullptr };                  
        OrderPointers::iterator location_;                          //location holds the current value that iteratior's pointing at within OrderEntry
      };

      std::map<Price, OrderPointers, std::greater<Price>> bids_;    //auto sorts highest to lowest on bids
      std::map<Price, OrderPointers, std::less<Price>> asks_;       //auto sorts lowest to highest on asks
      std::unordered_map<OrderId,OrderEntry> orders_;               


      bool CanMatch(Side side, Price price) const {       //adding match method && canMatch method 
        if (side == Side::Buy) {                          //if incoming order is buy side

          if (asks_.empty())
            return false;
          
          const auto& [bestAsk, ...] = *asks_.begin();
          return price >= bestPrice;
        }

        if (bids_.empty())
          return false; 

        const auto& [bestBid]

        }



      }


  
  };

