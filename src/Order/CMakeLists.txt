add_library(Order INTERFACE)

target_include_directories(Order
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
