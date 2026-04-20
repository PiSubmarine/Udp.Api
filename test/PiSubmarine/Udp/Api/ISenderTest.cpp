#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Udp/Api/ISender.h"

namespace PiSubmarine::Udp::Api
{
    TEST(ISenderTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<ISender>);
    }
}
