#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Udp/Api/IBindable.h"

namespace PiSubmarine::Udp::Api
{
    TEST(IBindableTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<IBindable>);
    }
}
