cmake_minimum_required(VERSION 3.8)
project(index-iterator-test)

add_executable(index-iterator-test 
    main.cpp
    test1.cpp
)

target_include_directories(index-iterator-test PRIVATE ./)
target_link_libraries(index-iterator-test PRIVATE index-iterator)