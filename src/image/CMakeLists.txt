#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

set(APP_DIRS ${APP_DIRS}
${CMAKE_CURRENT_SOURCE_DIR}
PARENT_SCOPE)

set(APP_SRCS ${APP_SRCS}
${CMAKE_CURRENT_SOURCE_DIR}/surface.cpp
${CMAKE_CURRENT_SOURCE_DIR}/imageloader.cpp
${CMAKE_CURRENT_SOURCE_DIR}/negativefilter.cpp
${CMAKE_CURRENT_SOURCE_DIR}/gradientfilter.cpp
${CMAKE_CURRENT_SOURCE_DIR}/kernel.cpp
${CMAKE_CURRENT_SOURCE_DIR}/gaussianfilter.cpp
${CMAKE_CURRENT_SOURCE_DIR}/sobelfilter.cpp
${CMAKE_CURRENT_SOURCE_DIR}/grayscalefilter.cpp
${CMAKE_CURRENT_SOURCE_DIR}/thresholdfilter.cpp
${CMAKE_CURRENT_SOURCE_DIR}/huefilter.cpp
PARENT_SCOPE)
