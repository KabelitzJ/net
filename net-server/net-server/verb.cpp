#include <net-server/verb.hpp>

namespace net {

verb from_string(std::string_view string) {
  if (string == "GET") {
    return verb::get;
  } else if (string == "PUT") {
    return verb::put;
  } else if (string == "PATCH") {
    return verb::patch;
  } else if (string == "POST") {
    return verb::post;
  } else if (string == "DELETE") {
    return verb::del;
  }

  return verb::unknown;
}

std::string_view to_string(verb verb) {
  switch (verb) {
    case verb::get:
      return "GET";
    case verb::put:
      return "PUT";
    case verb::patch:
      return "PATCH";
    case verb::post:
      return "POST";
    case verb::del:
      return "DELETE";
    case verb::unknown:
    default:
      return "UNKNOWN";
  }
}

std::ostream& operator<<(std::ostream& output_stream, verb verb) {
  output_stream << to_string(verb);
}

} // namespace net
