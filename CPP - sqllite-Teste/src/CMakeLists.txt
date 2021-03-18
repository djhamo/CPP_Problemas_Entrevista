
cmake_minimum_required (VERSION 3.8)

IF (WIN32)
    find_package(unofficial-sqlite3 CONFIG REQUIRED)
ELSE()    
    find_package(SQLite3 REQUIRED)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lsqlite3 -lgmock -lpthread -lm")
ENDIF()

add_library(SqlLite sqllite.cpp sqllite.h )
include_directories("../src")
target_include_directories(SqlLite PRIVATE ${SQLite3_INCLUDE_DIRS})
IF (WIN32)
    target_link_libraries(SqlLite PRIVATE unofficial::sqlite3::sqlite3)
ELSE()  
    target_link_libraries(SqlLite PRIVATE ${SQLite3_LIBRARIES} )
ENDIF()

add_subdirectory(test)