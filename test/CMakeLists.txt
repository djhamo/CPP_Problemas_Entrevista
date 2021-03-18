include(GoogleTest) # To use gtest_discover_tests
#gtest_discover_tests(Primitive_test)

find_package(Threads REQUIRED)
#add_subdirectory(googletest)
find_package(GTest CONFIG REQUIRED)

include_directories(".\\googletest\\googlemock\\include")

add_executable(Primitive_test primitive_test.cpp )
add_executable(Array_test array_test.cpp )

if(WIN32)
    target_include_directories(Primitive_test PRIVATE "${GMOCK_INCLUDE_DIRS}" "${GTEST_INCLUDE_DIRS}")
    target_link_libraries(Primitive_test PRIVATE Primitive GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

    target_include_directories(Array_test PRIVATE "${GMOCK_INCLUDE_DIRS}" "${GTEST_INCLUDE_DIRS}")
    target_link_libraries(Array_test PRIVATE Array GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
ELSE()
    target_include_directories(Primitive_test PRIVATE "${GMOCK_INCLUDE_DIRS}" "${GTEST_INCLUDE_DIRS}")
    target_link_libraries(Primitive_test PRIVATE Primitive gmock gtest gmock_main gtest_main ${CMAKE_THREAD_LIBS_INIT})
ENDIF()    