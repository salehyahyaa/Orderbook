#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <limits>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <memeory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>

enum class OrderType {

  GoodTillCancel,
  FillAndKill,
};


enum class Side {
  Buy,
  Sell
};


using Price = std::int32_t;                          //int == 4 bytes //alias
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;                      //int == 8 bytes


struct LevelInfo {                                 //used in public API's to get information about the state of the orderbook
  Price price;
  Quantity quantity;
};

using LevelInfos = std::vector<LevelInfo>; //LevelInfos == objects within the array Levelinfo {object1, object2}, each object within the array have INT Price/Quantity 

class OrderbookLevelInfos {
  
  public:
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
      : bids_ { bids },                                       //intinlizing fields within constrctor 
        asks_ { asks }
    { }

    const LevelInfos& GetBids() const { return bids_;}       //public API
    const LevelInfos& GetAsks() const { return asks_;}      //Public API


  private: 
    LevelInfos bids_;                                        //Private API
    LevelInfos asks_;                                        //Private API //now we have the interal state of what represents an orderbook such as each row has a ask and bid price
  };
//now we describe things we will add to the orderbook whitch is order objects(orderType, orderID, side, price, quantity, other apis to get filled, wheather they are filled, etc)

class Order {
  
  public:                                                                                      //<--constructor 
    Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
    : orderType_ { orderType },
      orderId_ { orderId },
      side_ { side },
      price_ { price},
      initialQuantity_ { quantity },            //3_t of quantites (intial quantity, the quantity remaining, the quantity that's been filled)
      remainingQuantity_ { quantity }           //remaming quantity always starts off as intintal quanity and wheahter or not its remaining tells us if its been filled or not
    {}

    OrderId GetOrderId() const { return orderId_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return orderType_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }
    
    void Fill(Quantity quantity) {
        if (quantity > GetRemainingQuantity())                    //if someone tried to fill more than what remains //quantity == how much someone is trying to fill
          throw std:: logic_error(std::format("cannot be filled for more than its remaining suppl.", GetOrderId()));
        
        remainingQuantity_ =  remainingQuantity_ - quantity;
  }
  
  
  private:
    OrderType orderType_;
    OrderId orderId_;
    Side side_;                 //represents the side of the orderbook your on... ASK || BID
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
  };

  using OrderPointer = std::shared_prt<Order>;
  using OrderPointers = std::list<OrderPointer>           //using a linked list to hold orders because a list gives an iterator that cannot be invailidated depsite the list can grow very, large this will be seful to identiofy where our order is in either bid or ask orderbook
                                                        //trade-off list over vector for simplicity as both get the job done but vector wouldve been...













int main() {

  return 0;
}
