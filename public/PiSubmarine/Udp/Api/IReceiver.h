#pragma once

#include <optional>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Udp/Api/Datagram.h"

namespace PiSubmarine::Udp::Api
{
    class IReceiver
    {
    public:
        virtual ~IReceiver() = default;

        [[nodiscard]] virtual Error::Api::Result<std::optional<Datagram>> TryReceive() = 0;
    };
}
