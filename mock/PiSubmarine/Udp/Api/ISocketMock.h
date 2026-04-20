#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Udp/Api/ISocket.h"

namespace PiSubmarine::Udp::Api
{
    class ISocketMock : public ISocket
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), Bind, (const Endpoint& localEndpoint), (override));
        MOCK_METHOD((Error::Api::Result<void>), Poll, (), (override));
        MOCK_METHOD((Error::Api::Result<void>), Send, (const Datagram& datagram), (override));
        MOCK_METHOD((Error::Api::Result<std::optional<Datagram>>), TryReceive, (), (override));
    };
}
