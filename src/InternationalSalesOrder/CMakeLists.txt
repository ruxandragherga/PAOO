add_library(InternationalSalesOrder InternationalSalesOrder.cpp)

target_include_directories(InternationalSalesOrder
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(InternationalSalesOrder PUBLIC Order SalesOrder)