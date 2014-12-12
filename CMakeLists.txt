cmake_minimum_required(VERSION 2.8)

project (sharedextern)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(extcontext SHARED src/context.cpp)

add_library(secore src/core.cpp)
target_link_libraries(secore extcontext)

add_library(secoreshared SHARED)
target_link_libraries(secoreshared secore)

add_library(seutil src/util.cpp)

add_library(seutilshared SHARED)
target_link_libraries(seutilshared secore seutil)

add_executable(seapp src/app.cpp)
target_link_libraries(seapp secoreshared seutilshared)
