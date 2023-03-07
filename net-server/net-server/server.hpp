#ifndef NET_SERVER_HPP_
#define NET_SERVER_HPP_

#include <memory>
#include <thread>

#include <boost/asio.hpp>
#include <boost/system.hpp>
#include <boost/beast.hpp>

#include <net-server/router.hpp>

namespace net {

class server {

public:

  server(std::uint16_t port);

  server(const server&) = delete;
  server(server&&) = delete;

  ~server();

  auto operator=(const server&) -> server& = delete;
  auto operator=(server&&) -> server& = delete;

  auto start(std::size_t thread_count = 1u) -> void;

  auto add_route(verb verb, const std::string& path, route::handle handle) -> void;

private:

  auto _accept() -> void;

  boost::asio::io_context _context;
  boost::asio::ip::tcp::acceptor _acceptor;
  std::shared_ptr<router> _router;
  std::vector<std::thread> _threads{};

}; // class server

} // namespace net

#endif // NET_SERVER_HPP_
