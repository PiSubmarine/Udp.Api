# Udp.Api

`PiSubmarine.Udp.Api` defines the minimal, polling-oriented UDP contract used by
higher-level protocol adapters.

## Responsibility

The API owns:

- UDP endpoint and datagram value types
- socket-level contract errors
- narrow bind/send/receive interfaces with no callbacks

The API does not own:

- protobuf schemas
- control or telemetry packet semantics
- threading policy beyond "no callbacks"

## Interface split

The project uses different roles for different protocol adapters, so the API is
split into:

- `IBindable`
- `ISender`
- `IReceiver`

Concrete implementations may implement all three at once, but higher-level
modules should depend only on the roles they actually need.

Polling itself is an implementation concern. `Udp.Api` intentionally does not
expose a `Poll()` method.
