#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include <cpprest/http_client.h>
#include <cpprest/uri_builder.h>

#include "Request.hpp"


class PoloniexClient
{

private:

  std::string buildAndSendRequest(const std::string & endpoint, std::string & query);

public:

  const std::string publicAPIEndpoint = "https://poloniex.com/public";
  const std::string tradingAPIEndpoint = "https://poloniex.com/tradingApi";

  //API Wrapper Methods

  //PUBLIC API
  std::string public_TickerRequest();
  std::string public_VolumeRequest();
  std::string public_OrderBookRequest(std::string & pairs, int depth);
  std::string public_TradeHistory(std::string & pairs, int & start, int & end);
  std::string public_TradeHistory(std::string & pairs);
  std::string public_ChartData(std::string & pairs, int & period, int & start, int & end);
  std::string public_Currencies();
  std::string public_LoanOrders(std::string & pair);


  //Trading API
  std::string balances();
  std::string completeBalances();
  std::string depositAddresses();
  std::string generateNewAddress();
  std::string depositsWithdrawals();
  std::string openOrders();
  std::string tradeHistory();
  std::string orderTrades();

  std::string buy();
  std::string sell();
  std::string cancelOrder();
  std::string moveOrder();

  std::string withdraw();
  std::string feeInfo();
  std::string availableAccountBalances();
  std::string tradableBalances();
  std::string transferBalance();
  std::string marginAccountSummary();
  std::string marginBuy();
  std::string marginSell();
  std::string getMarginPosition();
  std::string closeMarginPosition();
  std::string openLoanOffers();
  std::string activeLoans();
  std::string lendingHistory();


  bool createLoanOffer();
  bool cancelLoanOffer();
  bool toggleAutoRenew();
  bool canConnect();
  bool isAuthenticated();





};
