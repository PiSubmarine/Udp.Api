#include <gtest/gtest.h>

#include "PiSubmarine/Udp/Api/ErrorCode.h"

namespace PiSubmarine::Udp::Api
{
    TEST(ErrorCodeTest, ConvertsToErrorCode)
    {
        const auto errorCode = make_error_code(ErrorCode::PayloadTooLarge);

        EXPECT_EQ(errorCode.value(), static_cast<int>(ErrorCode::PayloadTooLarge));
        EXPECT_STREQ(errorCode.category().name(), "PiSubmarine.Udp.Api");
    }
}
