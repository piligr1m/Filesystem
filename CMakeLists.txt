cmake_minimum_required(VERSION 2.8)

project(CH CXX)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS filesystem regex) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(include)
    enable_testing()
add_executable(test_filesystem sources/main.cpp)
    target_link_libraries(progname ${Boost_LIBRARIES})
    add_test(NAME ${PROJECT_NAME} COMMAND test_filesystem)
endif()


