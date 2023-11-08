add_library(SalesOrder SalesOrder.cpp)

target_include_directories(SalesOrder
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(SalesOrder PUBLIC Order)