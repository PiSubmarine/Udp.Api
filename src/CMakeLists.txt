include("${PISUBMARINE_BUILD_SYSTEM}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        PiSubmarine/Udp/Api/ErrorCode.cpp
        "../public/PiSubmarine/Udp/Api/Endpoint.h"
        "../public/PiSubmarine/Udp/Api/Datagram.h"
        "../public/PiSubmarine/Udp/Api/ErrorCode.h"
        "../public/PiSubmarine/Udp/Api/ISocket.h")
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Error.Api)
