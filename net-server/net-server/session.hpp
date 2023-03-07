#ifndef NET_SESSION_HPP_
#define NET_SESSION_HPP_

#include <string>
#include <memory>

#include <boost/asio.hpp>
#include <boost/system.hpp>
#include <boost/beast.hpp>

#include <net-server/router.hpp>
#include <net-server/request.hpp>

namespace net {

class session : public std::enable_shared_from_this<session> {

public:

  session(boost::asio::ip::tcp::socket socket, std::shared_ptr<router> router);

  auto start() -> void;

private:

  auto _read_request() -> void;

  auto _handle_request() -> void;

  auto _create_response() -> void;

  auto _write_response() -> void;

  auto _stop() -> void;


  boost::asio::ip::tcp::socket _socket;
  std::shared_ptr<router> _router;
  std::string _request;
  std::string _response;

}; // class session

} // namespace net

#endif // NET_SESSION_HPP_
