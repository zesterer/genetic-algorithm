cmake_minimum_required(VERSION 2.6)

set(APP_NAME genetic-algorithm)

project(${APP_NAME} CXX)

set(APP_SRCS)
set(APP_LIBS)
set(APP_DIRS)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_definitions(-std=c++11 -Wall -g3)

find_package(PkgConfig REQUIRED)

#Set CMake modules path
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})

#pkg_search_module(FreeImage REQUIRED)

if (FREEIMAGE_FOUND)
	set(APP_DIRS ${APP_DIRS} ${FREEIMAGE_INCLUDE_DIR})
	set(APP_LIBS ${APP_LIBS} ${FREEIMAGE_LIBRARIES})
else ()
	message("FreeImage could not be found, and is required to build this library.")
endif ()


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${APP_DIRS})

add_executable(${APP_NAME} ${APP_SRCS})

target_link_libraries(${APP_NAME} ${APP_LIBS})
