#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Udp/Api/ISocket.h"

namespace PiSubmarine::Udp::Api
{
    TEST(ISocketTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<ISocket>);
    }
}
