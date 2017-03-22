#include "Request.hpp"


//Constructor taking the complete url to be sent to API
Request::Request(const std::string & baseUri, std::string & query)
  :baseUri(baseUri), query(query)
{}

//This method should return false if the request was bad
//It should also update the response if success
bool Request::sendRequest()
{
    bool success;
    http_client client(U(Request::baseUri));

    std::string query = "";

   client
      // send the HTTP GET request asynchronous
     .request(methods::GET, Request::query)
      // continue when the response is available
     .then([&](http_response response) -> pplx::task<json::value>
      {
         // if the status is OK extract the body of the response into a JSON value
         // works only when the content type is application\json
         if(response.status_code() == status_codes::OK)
         {
            return response.extract_json();
         }

         // return an empty JSON value
         return pplx::task_from_result(json::value());
      })
      // continue when the JSON value is available
      .then([&](pplx::task<json::value> previousTask)
      {
         // get the JSON value from the task and display content from it
         try
         {
            json::value const & v = previousTask.get();
            Request::response = v.serialize();
            success = true;
         }
         catch (http_exception const & e)
         {
             success = false;
             std::cout << e.what() << std::endl;
         }
      })
      .wait();


  return success;
}
