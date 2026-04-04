#pragma once 
#include <Usings.h>

struct LevelInfo {                                 //used in public API's to get information about the state of the orderbook
  Price price;
  Quantity quantity;
};

using LevelInfos = std::vector<LevelInfo>; //LevelInfos == objects within the array Levelinfo {object1, object2}, each object within the array have INT Price/Quantity 