#pragma once

#include <optional>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Udp/Api/Datagram.h"

namespace PiSubmarine::Udp::Api
{
    class ISocket
    {
    public:
        virtual ~ISocket() = default;

        [[nodiscard]] virtual Error::Api::Result<void> Bind(const Endpoint& localEndpoint) = 0;
        [[nodiscard]] virtual Error::Api::Result<void> Poll() = 0;
        [[nodiscard]] virtual Error::Api::Result<void> Send(const Datagram& datagram) = 0;
        [[nodiscard]] virtual Error::Api::Result<std::optional<Datagram>> TryReceive() = 0;
    };
}
