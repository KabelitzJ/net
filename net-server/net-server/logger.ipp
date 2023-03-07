#include <net-server/logger.hpp>

namespace net {

template<typename... Args>
auto logger::info(const std::string& name, format_string_type<Args...> format, Args&&... args) -> void {
  _logger(name).info(format, std::forward<Args>(args)...);
}

template<typename Type>
auto logger::info(const std::string& name, const Type& value) -> void {
  _logger(name).info(value);
}

template<typename... Args>
auto logger::error(const std::string& name, format_string_type<Args...> format, Args&&... args) -> void {
  _logger(name).error(format, std::forward<Args>(args)...);
}

template<typename Type>
auto logger::error(const std::string& name, const Type& value) -> void {
  _logger(name).error(value);
}

} // namespace net
