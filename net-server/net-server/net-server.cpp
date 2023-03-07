#include <iostream>
#include <array>
#include <string>
#include <mutex>
#include <sstream>
#include <unordered_map>
#include <regex>

#include <nlohmann/json.hpp>

#include <net-server/logger.hpp>
#include <net-server/server.hpp>
#include <net-server/request.hpp>
#include <net-server/response.hpp>

auto main(int argc, const char** argv) -> int {
  auto server = net::server{8888};

  server.add_route(net::verb::get, "/", [](const net::request& request) -> net::response {
    static_cast<void>(request);

    auto response = net::response{};

    return response;
  });

  server.start();

  return 0;
}
