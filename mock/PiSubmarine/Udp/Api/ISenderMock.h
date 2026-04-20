#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Udp/Api/ISender.h"

namespace PiSubmarine::Udp::Api
{
    class ISenderMock : public ISender
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), Send, (const Datagram& datagram), (override));
    };
}
