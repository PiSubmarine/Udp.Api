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

        /// <summary>
        /// Attempts to receive a single datagram without blocking.
        /// </summary>
        /// <returns>
        /// <c>std::unexpected(error)</c> if the receive operation failed;
        /// a successful result containing <c>std::nullopt</c> if no datagram is currently available;
        /// or a successful result containing a <see cref="Datagram"/> if one was received.
        /// </returns>
        [[nodiscard]] virtual Error::Api::Result<std::optional<Datagram>> TryReceive() = 0;
    };
}
