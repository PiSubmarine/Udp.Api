# Udp.Api

`PiSubmarine.Udp.Api` defines the minimal, polling-oriented UDP contract used by
higher-level protocol adapters.

## Responsibility

The API owns:

- UDP endpoint and datagram value types
- socket-level contract errors
- a polling interface with no callbacks

The API does not own:

- protobuf schemas
- control or telemetry packet semantics
- threading policy beyond "no callbacks"

## Polling model

The project is single-threaded and tick-based, so UDP integration is explicit:

- `Poll()` drains the OS socket in non-blocking mode into an internal receive
  queue owned by the implementation
- `TryReceive()` pops one already-buffered datagram if available
- `Send()` sends one datagram immediately

This lets protocol modules decide when socket work happens inside their own tick
flow without exposing callback-style APIs.
