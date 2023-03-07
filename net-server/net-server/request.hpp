#ifndef NET_REQUEST_HPP_
#define NET_REQUEST_HPP_

#include <string>

#include <net-server/verb.hpp>

namespace net {

class request {

  friend class session;

public:

  auto verb() -> verb;
  auto path() -> const std::string&;

private:

  request(const std::string& text);

  net::verb _verb;
  std::string _path;

}; // class request

} // namespace net

#endif // NET_REQUEST_HPP_
