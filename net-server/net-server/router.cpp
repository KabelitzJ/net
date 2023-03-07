#include <net-server/router.hpp>

#include <fmt/format.h>

namespace net {

route::route(const std::string& path, handle handle)
: _path{path},
  _handle{std::move(handle)} { }

auto route::operator()(const request& request) -> response {
  return _handle(request);
}

auto router::add_route(verb verb, const std::string& path, route::handle handle) -> void {
  _routes[verb].push_back(route{path, std::move(handle)});
}

auto router::resolve(verb verb, const std::string& path) -> route {
  if (auto routes = _routes.find(verb); routes != _routes.end()) {

  }

  throw routing_error{fmt::format("Could not resolve route '{}'", path)};
}

} // namespace net
