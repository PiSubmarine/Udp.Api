#pragma once

#include <system_error>

namespace PiSubmarine::Udp::Api
{
    enum class ErrorCode
    {
        AlreadyBound = 1,
        NotBound,
        InvalidEndpoint,
        PayloadTooLarge,
        ReceiveQueueOverflow
    };

    [[nodiscard]] std::error_code make_error_code(ErrorCode errorCode) noexcept;
}

namespace std
{
    template<>
    struct is_error_code_enum<PiSubmarine::Udp::Api::ErrorCode> : true_type
    {
    };
}
