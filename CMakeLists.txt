cmake_minimum_required(VERSION 2.8)

project (sharedextern)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(secore SHARED src/core.cpp)

add_library(seutil SHARED src/util.cpp)
target_link_libraries(seutil secore)

add_executable(seapp src/app.cpp)
target_link_libraries(seapp secore seutil)
