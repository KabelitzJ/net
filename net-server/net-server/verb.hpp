#ifndef NET_VERB_HPP_
#define NET_VERB_HPP_

#include <cinttypes>
#include <string_view>
#include <ostream>

namespace net {

enum class verb : std::uint8_t {
  unknown,
  post,
  get,
  put,
  patch,
  del
}; // enum class verb

verb from_string(std::string_view string);

std::string_view to_string(verb verb);

std::ostream& operator<<(std::ostream& output_stream, verb verb);

} // namespace net

#endif // NET_VERB_HPP_
