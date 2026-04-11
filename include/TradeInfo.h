#pragma once 
#include "Usings.h"
//we now need to represent what happens when a order is matched. we will use a trade Object to represent this
//tradeObject: an aggragation of 2 trade info objects | tradeInfoObject for the BID && tradeInfoObject for the ASK //because a bid has to match an ask and vise versa
  

struct TradeInfo {    //every TradeInfo(is an object) that has OrderId of whats traded
    OrderId orderId_;
    Price price_;
    Quantity Quantity_;
  };
