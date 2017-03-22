#include <iostream>
#include <ctime>

#include "./PoloniexClient.hpp"


int main(int argc, char* argv[])
{


  PoloniexClient c;
  //  std::cout << c.public_TickerRequest() << std::endl;
  //  std::cout << c.public_VolumeRequest() << std::endl;
  std::string all = "BTC_NXT";
  int start = std::time(0)-100000;
  int end = std::time(0);
  int seconds = 1800;
  //  std::cout << c.public_OrderBookRequest(all, 10) << std::endl;
  //  std::cout << c.public_TradeHistory(all) << std::endl;
  std::cout << c.public_ChartData(all, seconds, start, end);

    return 0;
}
