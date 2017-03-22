#include "PoloniexClient.hpp"


std::string PoloniexClient::buildAndSendRequest(const std::string & endpoint, std::string & query){

  //Create the request object
  Request r(endpoint, query);

  //Send the request and if success, return the response.
  if(r.sendRequest())
    {
      return r.response;
    }
  else
    {
      return "FAIL";
    }

}

//================= PUBLIC API METHODS ===================

/*** Grab the current ticker for all markets ***/
std::string PoloniexClient::public_TickerRequest(){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnTicker")
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}


/***Returns the 24-hour volume for all markets, plus totals for primary currencies.***/
std::string PoloniexClient::public_VolumeRequest(){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","return24hVolume")
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}

std::string PoloniexClient::public_OrderBookRequest(std::string & pairs, int depth){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnOrderBook")
    .append_query("currencyPair", pairs)
    .append_query("depth", depth)
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}

/**Takes Pairs and start and ending UNIX timestamps**/
std::string PoloniexClient::public_TradeHistory(std::string & pairs, int & start, int & end){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnTradeHistory")
    .append_query("currencyPair", pairs)
    .append_query("start", start)
    .append_query("end", end)
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}



/**Takes Pair and returns the most recent 200 trades in that market**/
std::string PoloniexClient::public_TradeHistory(std::string & pairs){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnTradeHistory")
    .append_query("currencyPair", pairs)
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}


/** Takes candlestick periods and start and end UNIX timestamps **/
/** Valid periods are 300, 900, 1800, 7200, 14400, and 86400 **/
std::string PoloniexClient::public_ChartData(std::string & pairs, int & period, int & start, int & end){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnChartData")
    .append_query("currencyPair", pairs)
    .append_query("period", period)
    .append_query("start", start)
    .append_query("end", end)
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}

std::string PoloniexClient::public_Currencies(){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnCurrencies")
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}

std::string PoloniexClient::public_LoanOrders(std::string & pair){

  // build the query parameters
  auto query =  uri_builder()
    .append_query("command","returnLoanOrders")
    .append_query("currency", pair)
    .to_string();

  return  PoloniexClient::buildAndSendRequest(PoloniexClient::publicAPIEndpoint, query);
}




bool PoloniexClient::canConnect(){

}


bool PoloniexClient::isAuthenticated(){

  return true;

}
