#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Udp/Api/IReceiver.h"

namespace PiSubmarine::Udp::Api
{
    TEST(IReceiverTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<IReceiver>);
    }
}
