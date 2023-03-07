#ifndef NET_SERVER_HPP_
#define NET_SERVER_HPP_

#include <memory>

#include <boost/asio.hpp>
#include <boost/system.hpp>
#include <boost/beast.hpp>

namespace net {

class server {

public:

  server(std::uint16_t port);

  ~server() = default;

  auto start() -> void;

private:

  auto _accept() -> void;

  boost::asio::io_context _context;
  boost::asio::ip::tcp::acceptor _acceptor;

}; // class server

} // namespace net

#endif // NET_SERVER_HPP_
