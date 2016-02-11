
project(FitzCore)
cmake_minimum_required(VERSION 3.3)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#gather our files
FILE (GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#build the executable
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_INCLUDE_DIRS})
add_executable(FitzCore ${SOURCES})
target_link_libraries(FitzCore ${CONAN_LIBS})

install(TARGETS FitzCore
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/install/bin)
