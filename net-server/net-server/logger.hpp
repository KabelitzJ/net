#ifndef NET_LOGGER_HPP_
#define NET_LOGGER_HPP_

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace net {

class logger {

public:

  template<typename... Args>
  using format_string_type = spdlog::format_string_t<Args...>;

  logger() = delete;

  ~logger() = default;

  template<typename... Args>
  static auto info(const std::string& name, format_string_type<Args...> format, Args&&... args) -> void;

  template<typename Type>
  static auto info(const std::string& name, const Type& value) -> void;

private:

  static auto _logger(const std::string& name) -> spdlog::logger&;

  static std::mutex _mutex;
  static std::unordered_map<std::string, spdlog::logger> _loggers;

}; // class logger

} // namespace net

#include <net-server/logger.ipp>

#endif // NET_LOGGER_HPP_
