#include <net-server/server.hpp>

#include <net-server/logger.hpp>
#include <net-server/session.hpp>

namespace net {

server::server(std::uint16_t port)
: _context{},
  _acceptor{_context, boost::asio::ip::tcp::endpoint{boost::asio::ip::tcp::v4(), port}} { }

auto server::start() -> void {
  logger::info("server", "Starting on {}", _acceptor.local_endpoint().port());

  _accept();

  _context.run();
}


auto server::_accept() -> void {
  _acceptor.async_accept([this](boost::system::error_code error_code, boost::asio::ip::tcp::socket socket){
    if (error_code) {
      logger::info("server", error_code.message());
      return;
    }

    std::make_shared<session>(std::move(socket))->start();

    _accept();
  });
}

} // namespace net
