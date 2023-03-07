#ifndef NET_UTILITY_HPP_
#define NET_UTILITY_HPP_

#include <string>
#include <vector>

namespace net {

auto split_string(const std::string& string, const std::string& delimiter) -> std::vector<std::string>;

auto trim_string(const std::string& string, const std::string& whitespace = " ") -> std::string;

} // namespace net

#endif // NET_UTILITY_HPP_
