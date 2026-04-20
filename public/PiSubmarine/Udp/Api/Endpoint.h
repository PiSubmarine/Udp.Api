#pragma once

#include <cstdint>
#include <string>

namespace PiSubmarine::Udp::Api
{
    struct Endpoint
    {
        std::string Address;
        std::uint16_t Port = 0;

        [[nodiscard]] bool operator==(const Endpoint&) const = default;
    };
}
