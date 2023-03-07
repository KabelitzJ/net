#include <net-server/request.hpp>

namespace net {

request::request(const std::string& text) {

}

auto request::verb() -> net::verb {
  return _verb;
}

auto request::path() -> const std::string& {
  return _path;
}

} // namespace net
