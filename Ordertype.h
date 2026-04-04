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
