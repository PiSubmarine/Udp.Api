#include "PiSubmarine/Udp/Api/ErrorCode.h"

#include <array>
#include <string_view>

namespace PiSubmarine::Udp::Api
{
    namespace
    {
        class ErrorCategory final : public std::error_category
        {
        public:
            [[nodiscard]] const char* name() const noexcept override
            {
                return "PiSubmarine.Udp.Api";
            }

            [[nodiscard]] std::string message(const int condition) const override
            {
                constexpr std::array<std::string_view, 6> Messages{
                    "success",
                    "socket already bound",
                    "socket not bound",
                    "invalid endpoint",
                    "payload too large",
                    "receive queue overflow"};

                const auto index = static_cast<std::size_t>(condition);
                if (index >= Messages.size())
                {
                    return "unknown UDP error";
                }

                return std::string(Messages[index]);
            }
        };
    }

    [[nodiscard]] std::error_code make_error_code(const ErrorCode errorCode) noexcept
    {
        static const ErrorCategory Category;
        return {static_cast<int>(errorCode), Category};
    }
}
