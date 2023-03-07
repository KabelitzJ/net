#include <net-server/server.hpp>

#include <net-server/logger.hpp>
#include <net-server/session.hpp>

namespace net {

server::server(std::uint16_t port)
: _context{},
  _acceptor{_context, boost::asio::ip::tcp::endpoint{boost::asio::ip::tcp::v4(), port}},
  _router{std::make_shared<router>()} { }

server::~server() {
  for (auto& thread : _threads) {
    thread.join();
  }
}

auto server::start(std::size_t thread_count) -> void {
  logger::info("server", "Starting on {}", _acceptor.local_endpoint().port());

  _accept();

  for (auto i = std::size_t{0}; i < thread_count; ++i) {
    _threads.push_back(std::thread{[this](){ _context.run(); }});
  }
}

auto server::add_route(verb verb, const std::string& path, route::handle handle) -> void {
  _router->add_route(verb, path, std::move(handle));
}

auto server::_accept() -> void {
  _acceptor.async_accept([this](boost::system::error_code error_code, boost::asio::ip::tcp::socket socket){
    if (error_code) {
      logger::error("server", error_code.message());
      return;
    }

    std::make_shared<session>(std::move(socket), _router)->start();

    _accept();
  });
}

} // namespace net
