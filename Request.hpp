#pragma once

#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include <iostream>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

#include <string>

/*** This class is used to perform an HTTP request to a RESTful webservice
 *   It will return the JSON response which will need to handled seperately.
 ***/

class Request
{

private:

  std::string baseUri;
  std::string query;

public:

  std::string response = "";

  //Constructor taking the complete url to be sent to API
  Request(const std::string & baseUri, std::string & query);

  //This method should return false if the request was bad
  //It should also update the response if success
  bool sendRequest();


};
