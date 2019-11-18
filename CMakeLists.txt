cmake_minimum_required(VERSION 2.8)

project(CH CXX)
hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)
add_library(filesys INTERFACE)
if (MSVC)
    add_definitions(/W4)
else()
    add_definitions(-Wall)
    add_definitions(-std=c++11)
endif()

include_directories(include)

enable_testing()

add_executable(test_filesystem sources/main.cpp)

target_include_directories(
filesys
INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(filesys INTERFACE Boost::filesystem)
target_link_libraries(main filesys)
add_test(NAME ${PROJECT_NAME} COMMAND test_filesystem)
