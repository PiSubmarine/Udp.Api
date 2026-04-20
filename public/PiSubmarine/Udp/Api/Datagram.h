#pragma once

#include <cstddef>
#include <vector>

#include "PiSubmarine/Udp/Api/Endpoint.h"

namespace PiSubmarine::Udp::Api
{
    struct Datagram
    {
        Endpoint Peer;
        std::vector<std::byte> Payload;

        [[nodiscard]] bool operator==(const Datagram&) const = default;
    };
}
