cmake_minimum_required(VERSION 3.20)

project(
    learn.cpp.compute
    VERSION 0.0.0
    LANGUAGES CXX
)

set(CMAKE_PROJECT_NAME ${PROJECT_NAME}-${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/other_cmake_module)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if( NOT CMAKE_BUILD_TYPE )
    #REM: [TODO] .|. Hmmm...
    set(
        CMAKE_BUILD_TYPE Release
        CACHE STRING "Choose the build type" FORCE
    )
endif()

add_subdirectory(src)



