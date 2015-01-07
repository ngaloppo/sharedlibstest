cmake_minimum_required(VERSION 2.8)

project (sharedextern)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# A test for shared libraries with static data
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


# A test for shared libraries with duplicate symbols

# static version of a third party lib
add_library(thirdparty_static src/thirdparty.cpp)
target_compile_definitions(thirdparty_static PRIVATE TP_VERSION=static)
# need to compile with position independent code (-fPIC) if we want to compile
# this static library into a dynamic library
set_target_properties(thirdparty_static PROPERTIES 
    TARGET_INDEPENDENT_CODE ON
    COMPILE_OPTIONS "-fPIC"
    )

# shared version of a third party lib (could be a different version than the
# static version above)
add_library(thirdparty_shared SHARED src/thirdparty.cpp)
target_compile_definitions(thirdparty_shared PRIVATE TP_VERSION=shared)

# a shared library that statically links to the third party lib
add_library(mylib_shared SHARED src/mylib.cpp)
target_link_libraries(mylib_shared thirdparty_static)

# By default, the UNIX shared library loader simply goes down the list of
# loaded libraries, and tries to find the given symbol. The first library to
# define the symbol "wins". We can modify this behavior on ELF systems with the
# -Bsymbolic and -Bsymbolic-functions flags. This goes against the normal linking
# behavior, so buyer be ware... o_O
# http://stackoverflow.com/questions/1054697/why-isnt-my-new-operator-called/1056738#1056738
set_target_properties(mylib_shared PROPERTIES 
    COMPILE_OPTIONS "-Wl,-Bsymbolic"
    LINK_FLAGS "-Wl,-Bsymbolic"
    )

add_executable(tpapp src/tpapp.cpp)
target_link_libraries(tpapp thirdparty_shared mylib_shared)
