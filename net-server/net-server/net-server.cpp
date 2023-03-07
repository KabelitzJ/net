#include <iostream>
#include <array>
#include <string>
#include <mutex>
#include <sstream>
#include <unordered_map>

#include <nlohmann/json.hpp>

#include <net-server/logger.hpp>
#include <net-server/server.hpp>

auto main(int argc, const char** argv) -> int {
  auto server = net::server{8888};

  server.start();

  return 0;
}
