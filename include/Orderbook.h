//An orderbook is a catelog that maintains all active buy and sell orders for a financial instrument, organized by price, time priority 
#include <map> 
#include <unordered_map>
#include <thread>
#include <condition_variable>
#include <mutex>

#include "Usings.h"
#include "Order.h"
#include "OrderModify.h"
#include "OrderbookLevelInfos.h"
#include "Trade.h"


class Orderbook {
    private:                                                        //when storing bids &&asks we'll use a map, bids sorted in ascneding order(best bids), asks sorted in desencding order(best ask), we will have O(1) easy access based on orderId
    
      struct OrderEntry {                                           //represents an order and its location in the orderbook
        OrderPointer order_{ nullptr };                  
        OrderPointers::iterator location_;                          //location holds the current value that iteratior's pointing at within OrderEntry
      };

      std::map<Price, OrderPointers, std::greater<Price>> bids_;    //auto sorts highest to lowest on bids
      std::map<Price, OrderPointers, std::less<Price>> asks_;       //auto sorts lowest to highest on asks
      std::unordered_map<OrderId,OrderEntry> orders_;               


      bool CanMatch(Side side, Price price) const {                 //adding match method && canMatch method 
        if (side == Side::Buy) {                                    //if incoming order is buy side

          if (asks_.empty())
            return false;
          
          const auto& [bestAsk, _] = *asks_.begin();                //grabs the first (lowest since the map is sorted) price from bestask (grabs first value from sorted map lowest to highest)
          return price >= bestAsk;
        
        }
        else {
          
          if (bids_.empty())
          return false; 

        const auto& [bestBid, _] = *bids_.begin();
        return price <= bestBid;
        }
      
      }

       
      
        Trades MatchOrders() {
          Trades trades; 
          trades.reserve(orders_.size());                            //so we are forward declaring here, pre allocating memeory for orders_ so the vector doesnt waste time resizing for higer perofrmace

          while (true) {
            if (bids_.empty() || asks_.empty());
              break;
            
            auto& [bidPrice, bids] = *bids_.begin();
            auto& [askPrice, asks] = *asks_.begin();

            if (bidPrice < askPrice) 
              break;
            
            while (bids.size() && asks.size()) {

              auto& bid = bids.front();
              auto& ask = asks.front(); //gets the first element from the asks map thats sorted sorted

              Quantity quantity = std::min(bid->GetRemainingQuantity(), ask->GetRemainingQuantity()); //bid represents a pointer to the order and we get the remainingQuantity of bid&&ask. Then assign that to quantity
              bid-> Fill(quantity);
              ask-> Fill(quantity);

              if (bid->isFilled()) {
                bids.pop_front();
                orders_.erase(bid->GetOrderId());
              }
              
              if (bids.empty()) {
                bids_.erase(bidPrice);
              }
              
              if (asks_.empty()) {
                asks_.erase(askPrice);
              }

              trades.push_back(Trade {
                TradeInfo{ bid->GetOrderId(), bid-> GetPrice(), quantity },
                TradeInfo{ask-> GetOrderId(), ask -> GetPrice(), quantity }
              });
            }
          }
          
          if (!bids_.empty()) {
            auto& [_, asks] = *asks_.begin(); //begin returns the first element in whatever container asks_ is
            auto& order = asks.front(); 
            if (order->GetOrderType() == OrderType::FillAndKill) {
              CancelOrder(order->GetOrderId());
            }
          }
        }

    public: 

        Trades Addorder(OrderPointer order) {
          if (orders_.contains(order->GetOrderId())) {
            return { };         //if we have a duplicate order incoming, the return statment exisiting out early wont allow the function to countie so duplicates never get added
          }

         if (order-> ) ...
        }






      };




/*
notes of time price priotirty
so basically in the actual dict they are sorted by greater and less than depending on side
and in a list of the orders location in memory is stored via time the orders regardless what was greater or lower but more so on the time it came in
*/