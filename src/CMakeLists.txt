cmake_minimum_required(VERSION 3.22.1)

project(MyProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Order)
add_subdirectory(SalesOrder)
add_subdirectory(InternationalSalesOrder)
add_subdirectory(Category)

add_executable(MyProject main.cpp)
# add_executable(MyProject main.cpp Category.cpp Order.cpp SalesOrder.cpp InternationalSalesOrder.cpp)


target_link_libraries(MyProject PUBLIC Order SalesOrder InternationalSalesOrder Category)

target_include_directories(MyProject PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Order"
    "${PROJECT_SOURCE_DIR}/SalesOrder"
    "${PROJECT_SOURCE_DIR}/InternationalSalesOrder"
    "${PROJECT_SOURCE_DIR}/Category"
)