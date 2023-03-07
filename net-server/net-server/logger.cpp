#include <net-server/logger.hpp>

namespace net {

std::mutex logger::_mutex{};
std::unordered_map<std::string, spdlog::logger> logger::_loggers{};

auto logger::_logger(const std::string& name) -> spdlog::logger& {
  auto lock = std::scoped_lock{_mutex};

  if (auto entry = _loggers.find("name"); entry != _loggers.end()) {
    return entry->second;
  }

  auto logger = spdlog::logger{name, std::make_shared<spdlog::sinks::stdout_color_sink_mt>()};
  logger.set_level(spdlog::level::debug);
  logger.set_pattern("[%Y-%m-%d %H:%M:%S] [%n] [%^%l%$] : %v");

  auto entry = _loggers.insert({name, std::move(logger)});

  return entry.first->second;
}

} // namespace net 
