cmake_minimum_required(VERSION 3.16.2) 
project(LivroEntrevista VERSION 0.1.0)

IF (WIN32)
  set(CMAKE_TOOLCHAIN_FILE C:\\Users\\Tiago\\Documents\\Projetos\\estudo-cpp\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
ENDIF()

add_subdirectory(src)
add_subdirectory(test)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE Primitive Array)
