#include <net-server/session.hpp>

#include <sstream>

#include <net-server/logger.hpp>

namespace net {

session::session(boost::asio::ip::tcp::socket socket)
: _socket{std::move(socket)} { }

auto session::start() -> void {
  _read_request();
}

auto session::_read_request() -> void {
  auto request_buffer = boost::asio::dynamic_buffer(_request);

  boost::asio::async_read_until(_socket, request_buffer, '\n', [this, self = shared_from_this()](boost::system::error_code error_code, std::size_t bytes_read){
    if (!error_code) {
      logger::info("session", "read: {}", error_code.message());
      _stop();
      return;
    }

    _handle_request();
  });
}

auto session::_handle_request() -> void {
  _create_response();
  _write_response();
}

auto session::_create_response() -> void {
  auto response_stream = std::stringstream{};

  response_stream << "HTTP/1.1 OK 200\r\n";
  response_stream << "Content-Type: text/html\r\n";
  response_stream << "Content-Length: 21\r\n";
  response_stream << "\r\n";
  response_stream << "<h1>Hello World!</h1>\r\n";

  _response = response_stream.str();
}

auto session::_write_response() -> void {
  auto response_buffer = boost::asio::buffer(_response);

  boost::asio::async_write(_socket, response_buffer, [this, self = shared_from_this()](boost::system::error_code error_code, std::size_t bytes_written){
    if (!error_code) {
      logger::info("session", "write: {}", error_code.message());
    }

    _stop();
  });
}

auto session::_stop() -> void {
  _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
  _socket.close();
}

} // namespace net
