#ifndef NET_ROUTER_HPP_
#define NET_ROUTER_HPP_

#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <stdexcept>

#include <net-server/request.hpp>
#include <net-server/response.hpp>
#include <net-server/verb.hpp>

namespace net {

class route {

public:

  using handle = std::function<response(const request&)>;

  route(const std::string& path, handle handle);

  auto operator()(const request& request) -> response;

private:

  std::string _path;
  handle _handle;

}; // class route

class routing_error : public std::runtime_error {

public:

  routing_error(const std::string& message) : std::runtime_error{message} { }

}; // routing_error

class router {

public:

  router() = default;

  auto add_route(verb verb, const std::string& path, route::handle handle) -> void;

  auto resolve(verb verb, const std::string& path) -> route;

private:

  std::unordered_map<verb, std::vector<route>> _routes;

}; // class router

} // namespace net

#endif // NET_ROUTER_HPP_
