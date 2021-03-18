add_subdirectory(sqlite3)

include_directories("./sqlite3/src")

add_library(Soundex_lib Soundex.cpp Soundex.h)
target_link_libraries(Soundex_lib sqlite3)