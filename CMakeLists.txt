#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(myproject)

#c++ 11 support
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories("${PROJECT_BINARY_DIR}/src")

# Define sources and executable
set(EXECUTABLE_NAME "t4nk")
add_executable(${EXECUTABLE_NAME} main.cpp game.h game.cpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
