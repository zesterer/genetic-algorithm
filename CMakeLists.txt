cmake_minimum_required(VERSION 2.6)

set(APP_NAME genetic-algorithm)

project(${APP_NAME} CXX)

set(APP_SRCS)
set(APP_LIBS)
set(APP_DIRS)

add_definitions(-std=c++11 -Wall -g3)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${APP_DIRS})

add_executable(${APP_NAME} ${APP_SRCS})

target_link_libraries(${APP_NAME} ${APP_LIBS})
