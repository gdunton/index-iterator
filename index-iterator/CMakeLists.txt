cmake_minimum_required(VERSION 3.8)
project(index-iterator)

add_library(index-iterator INTERFACE)

target_include_directories(index-iterator INTERFACE include/)
target_compile_features(index-iterator INTERFACE cxx_std_11)

target_sources(index-iterator 
    INTERFACE 
        ${CMAKE_CURRENT_LIST_DIR}/include/index-iterator.hpp 
        ${CMAKE_CURRENT_LIST_DIR}/include/detail/iter_and_index_wrapper.hpp
)