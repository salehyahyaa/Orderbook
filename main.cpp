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
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>

enum class Ordertype {

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
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks);
      : bids_{ bids },
        asks_{ asks }
    { }

    const LevelInfos& GetBids() const { return bids_;}       //public API
    const LevelInfos& GetAsks() const { reuturn asks_;}      //Public API

  private:




};










int main() {

  return 0;
}
