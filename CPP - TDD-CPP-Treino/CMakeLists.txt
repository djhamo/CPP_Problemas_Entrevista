cmake_minimum_required(VERSION 3.18.2) 
project(Soundex VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Soundex main.cpp)

add_subdirectory(googletest)
add_subdirectory(example)
#add_subdirectory(sqlite3)

target_link_libraries(Soundex PUBLIC Soundex_lib gmock_main gmock gtest gtest_main)

include(GoogleTest) # To use gtest_discover_tests

#gtest_discover_tests(example)
