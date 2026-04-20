#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Udp/Api/Endpoint.h"

namespace PiSubmarine::Udp::Api
{
    class IBindable
    {
    public:
        virtual ~IBindable() = default;

        [[nodiscard]] virtual Error::Api::Result<void> Bind(const Endpoint& localEndpoint) = 0;
    };
}
