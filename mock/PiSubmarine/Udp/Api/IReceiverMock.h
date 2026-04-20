#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Udp/Api/IReceiver.h"

namespace PiSubmarine::Udp::Api
{
    class IReceiverMock : public IReceiver
    {
    public:
        MOCK_METHOD((Error::Api::Result<std::optional<Datagram>>), TryReceive, (), (override));
    };
}
