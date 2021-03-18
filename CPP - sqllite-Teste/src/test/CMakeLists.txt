include(GoogleTest) # To use gtest_discover_tests
#gtest_discover_tests(SqlLiteTest)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
add_executable(SqlLiteTest sqllite_test.cpp )

if(WIN32)
    target_link_libraries(SqlLiteTest PRIVATE SqlLite GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
ELSE()
    target_include_directories(SqlLiteTest PRIVATE "${GMOCK_INCLUDE_DIRS}" "${GTEST_INCLUDE_DIRS}")
    target_link_libraries(SqlLiteTest PRIVATE SqlLite gmock gtest gmock_main gtest_main ${CMAKE_THREAD_LIBS_INIT})
ENDIF()    