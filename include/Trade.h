#pragma once 
#include "TradeInfo.h" //libaries

  class Trade {           //represents bid and ask side trades //class intilization
    public: 
      Trade(const TradeInfo& bidTrade, const TradeInfo& askTrade)//constructor
      : bidTrade_ { bidTrade }, //Intilizing object
        askTrade_ { askTrade }
    { }

    const TradeInfo& GetBidTrade() const { return bidTrade_; }
    const TradeInfo& GetAskTrade() const { return askTrade_; }//getter method
  
  private:
    TradeInfo bidTrade_;
    TradeInfo askTrade_;
  };

    //because there can be more than 1 order/execution we return a vector of orders since a order can take shares from multiple ask'ers causing multiple matches
    using Trades = std::vector<Trade>;
