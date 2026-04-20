#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Udp/Api/Datagram.h"

namespace PiSubmarine::Udp::Api
{
    class ISender
    {
    public:
        virtual ~ISender() = default;

        [[nodiscard]] virtual Error::Api::Result<void> Send(const Datagram& datagram) = 0;
    };
}
