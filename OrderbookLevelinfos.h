#pragma once //header file guard
#include "LevelInfo.h"

class OrderbookLevelInfos {
  
  public:
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
      : bids_ { bids },                                       //intinlizing fields within constrctor 
        asks_ { asks }                                        //asks_ == self.asks  #python version
    { }

    const LevelInfos& GetBids() const { return bids_;}       //getter method
    const LevelInfos& GetAsks() const { return asks_;}      //getter method


  private: 
    LevelInfos bids_;                                        //Private API
    LevelInfos asks_;                                        //Private API //now we have the interal state of what represents an orderbook such as each row has a ask and bid price
  };
