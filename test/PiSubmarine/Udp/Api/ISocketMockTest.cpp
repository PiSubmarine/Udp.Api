#include <gtest/gtest.h>

#include "PiSubmarine/Udp/Api/ISocketMock.h"

namespace PiSubmarine::Udp::Api
{
    TEST(ISocketMockTest, SupportsPollingAndSendingDatagrams)
    {
        ISocketMock socket;
        const Datagram outgoing{
            .Peer = Endpoint{"127.0.0.1", 9000},
            .Payload = {std::byte{0x01}, std::byte{0x02}}};
        const Datagram incoming{
            .Peer = Endpoint{"127.0.0.1", 9001},
            .Payload = {std::byte{0x0A}}};

        EXPECT_CALL(socket, Poll())
            .WillOnce(testing::Return(Error::Api::Result<void>{}));
        EXPECT_CALL(socket, Send(outgoing))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));
        EXPECT_CALL(socket, TryReceive())
            .WillOnce(testing::Return(Error::Api::Result<std::optional<Datagram>>(incoming)));

        EXPECT_TRUE(socket.Poll().has_value());
        EXPECT_TRUE(socket.Send(outgoing).has_value());

        const auto receiveResult = socket.TryReceive();
        ASSERT_TRUE(receiveResult.has_value());
        ASSERT_TRUE(receiveResult->has_value());
        EXPECT_EQ(receiveResult->value(), incoming);
    }
}
