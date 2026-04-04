#pragma once 

#include <list>
#include <exception>
#include <format>

#include "OrderType.h"
#include "Side.h"
#include "Usings.h"
#include "Constants.h"


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
    { }

    OrderId GetOrderId() const { return orderId_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return orderType_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }
    
    void Fill(Quantity quantity) {
        if (quantity > GetRemainingQuantity())                    //if someone tried to fill more than what remains //quantity == how much someone is trying to fill
          throw std:: logic_error(std::logic_error("cannot be filled for more than its remaining suppl." + std::to_string(GetOrderId())));
        
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

  using OrderPointer = std::shared_ptr<Order>;
  using OrderPointers = std::list<OrderPointer>;          //using a linked list to hold orders because a list gives an iterator that cannot be invailidated depsite the list can grow very large, this will be useful to identiofy where our order is in either bid or ask orderbook
                                                        //trade-off list over vector for simplicity as both get the job done but vector wouldve been...
