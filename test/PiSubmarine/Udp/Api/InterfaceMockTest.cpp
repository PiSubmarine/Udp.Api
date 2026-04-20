#include <gtest/gtest.h>

#include "PiSubmarine/Udp/Api/IBindableMock.h"
#include "PiSubmarine/Udp/Api/IReceiverMock.h"
#include "PiSubmarine/Udp/Api/ISenderMock.h"

namespace PiSubmarine::Udp::Api
{
    TEST(InterfaceMockTest, SupportsBindingSendingAndReceiving)
    {
        IBindableMock bindable;
        ISenderMock sender;
        IReceiverMock receiver;
        const Endpoint localEndpoint{"127.0.0.1", 9000};
        const Datagram datagram{
            .Peer = Endpoint{"127.0.0.1", 9001},
            .Payload = {std::byte{0x01}, std::byte{0x02}}};

        EXPECT_CALL(bindable, Bind(localEndpoint))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));
        EXPECT_CALL(sender, Send(datagram))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));
        EXPECT_CALL(receiver, TryReceive())
            .WillOnce(testing::Return(Error::Api::Result<std::optional<Datagram>>(datagram)));

        EXPECT_TRUE(bindable.Bind(localEndpoint).has_value());
        EXPECT_TRUE(sender.Send(datagram).has_value());

        const auto receiveResult = receiver.TryReceive();
        ASSERT_TRUE(receiveResult.has_value());
        ASSERT_TRUE(receiveResult->has_value());
        EXPECT_EQ(receiveResult->value(), datagram);
    }
}
