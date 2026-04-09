#pragma once 
#include <Usings.h>

struct LevelInfo {                                 //used in public API's to get information about the state of the orderbook
  Price price;                                     //gets price state of the orderbook
  Quantity quantity;                               //gets quantity state of the orderbook
};

using LevelInfos = std::vector<LevelInfo>; //LevelInfos == objects within the array Levelinfo {object1, object2}, each object within the array have INT Price/Quantity 