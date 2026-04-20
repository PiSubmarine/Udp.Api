#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Udp/Api/IBindable.h"

namespace PiSubmarine::Udp::Api
{
    class IBindableMock : public IBindable
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), Bind, (const Endpoint& localEndpoint), (override));
    };
}
