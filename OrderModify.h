#pragma once 
#include <Order.h>
/*
WE NEED TO CREATE A REPRESENTATION FOR AN ORDER THAT CAN BE MODIFIED
-add //need's Order (orderType, orderId, side, price, quantity) 
-modify //need's a representation of an order that can be converted to new order |
    to modify means to cancel then replace | CANCEL == (orderId) to do, REPLACE == (price, quantity, side) to do    
-cancel //need orderId |
*/


  class OrderModify {
    public: 
      OrderModify(OrderId orderId, Side side, Price price, Quantity quantity)
      : orderId_ { orderId },
        side_ { side },
        price_ { price },
        quantity_ { quantity }
      { }

      OrderId GetOrderId() const { return orderId_; }
      Price GetPrice() const { return price_; }
      Side GetSide() const { return side_; }
      Quantity GetQuantity() const { return quantity_; }

      OrderPointer ToOrderPointer(OrderType type) const {              //taking an existing order and transforming it with this OrderModify class into a new order,  //for this project the only orders we can modify are GoodTillCancel but this in case we want to support more order types in future
        return std::make_shared<Order>(type, GetOrderId(), GetSide(), GetPrice(), GetQuantity());
      }
    
    private: 
       OrderId orderId_;
       Price price_;
       Side side_;
       Quantity quantity_;
  };
//now we have order, order modify, and orderCancel just needs the orderId
