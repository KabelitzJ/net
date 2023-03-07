#include <net-server/utility.hpp>

namespace net {

auto split_string(const std::string& string, const std::string& delimiter) -> std::vector<std::string> {
  auto token = std::string{};
  auto result = std::vector<std::string>{};

  auto last = std::size_t{0};
  auto next = std::size_t{0};

  while ((next = string.find(delimiter, last)) != std::string::npos) {   
    result.push_back(trim_string(string.substr(last, next-last), " \t\r\n"));   
    last = next + 1; 
  }

  result.push_back(trim_string(string.substr(last), " \t\r\n"));

  return result;
}

auto trim_string(const std::string& string, const std::string& whitespace) -> std::string {
  const auto begin = string.find_first_not_of(whitespace);
  if (begin == std::string::npos) {
    return std::string{};
  }

  const auto end = string.find_last_not_of(whitespace);
  const auto range = end - begin + 1;

  return string.substr(begin, range);
}

} // namespace net
