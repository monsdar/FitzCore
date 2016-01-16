cmake_minimum_required(VERSION 3.3)

#gather Thirdparty
set (ZMQ_LIBRARY "E:/Github/ZeroMQ-4.0.4/lib/libzmq-v120-mt-4_0_4.lib" CACHE FILEPATH "Sets the path to the ZMQ library")
set (ZMQ_INCLUDES "E:/Github/ZeroMQ-4.0.4/include" CACHE PATH "Sets the path to the ZMQ includes")

#gather our files
FILE (GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#build the executable
include_directories(${ZMQ_INCLUDES})
add_executable(FitznetCore ${SOURCES})
target_link_libraries(FitznetCore ${ZMQ_LIBRARY})


install(TARGETS FitznetCore
        DESTINATION E:/Github/Fitznet/install/bin)
        
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/script/startCore.bat
        DESTINATION E:/Github/Fitznet/install/bin)
