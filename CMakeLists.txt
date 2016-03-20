cmake_minimum_required(VERSION 3.2)
project(ECE368_Space_Tank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Decleration.h)
add_executable(ECE368_Space_Tank ${SOURCE_FILES} Decleration.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ECE368_Space_Tank ${SFML_LIBRARIES})
endif()