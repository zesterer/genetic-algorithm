cmake_minimum_required(VERSION 2.6)

set(APP_NAME genetic-algorithm)

project(${APP_NAME} CXX)

set(APP_SRCS)
set(APP_LIBS)
set(APP_DIRS)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_definitions(-std=c++11 -Wall -g3)


find_package(SFML 2 REQUIRED system window graphics network audio)

if (SFML_FOUND)
	set(APP_DIRS ${APP_DIRS} ${SFML_INCLUDE_DIR})
	set(APP_LIBS ${APP_LIBS} ${SFML_LIBRARIES})
else ()
	message("SFML could not be found, and is required to build this library.")
endif ()


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${APP_DIRS})

add_executable(${APP_NAME} ${APP_SRCS})

target_link_libraries(${APP_NAME} ${APP_LIBS})
