cmake_minimum_required(VERSION 3.15.4)

project(CH CXX)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS filesystem regex) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(include)
    add_library(MyLibrary STATIC filesystem.cpp)
    target_link_libraries(MyLibrary sources/filesystem.cpp)
add_executable(test_filesystem sources/main.cpp)

endif()


