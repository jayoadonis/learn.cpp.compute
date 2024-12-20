
function(add_link_private_and_include pkg_name pkg_path)
    file(
        GLOB_RECURSE
        __SRC_MAIN_DIR ${CMAKE_SOURCE_DIR}/src/main/${pkg_path}/*.cpp
    )
    add_library(${pkg_name} ${__SRC_MAIN_DIR})
    target_include_directories(
        ${pkg_name}
        PUBLIC ${CMAKE_SOURCE_DIR}/src/include
    )
endfunction()


add_link_private_and_include(
    ${PROJECT_NAME}.init-${PROJECT_VERSION}
    "learn/cpp/compute"
)


add_link_private_and_include(
    ${PROJECT_NAME}.sample_ii-${PROJECT_VERSION}
    "learn/cpp/compute/sample_ii"
)

#REM: [TODO] .|. Hmmm...
file(
    GLOB_RECURSE
    __SRC_MAIN_EXE ${CMAKE_SOURCE_DIR}/src/main/learn/cpp/compute/main.cpp
)

add_executable(
    ${PROJECT_NAME}-${PROJECT_VERSION}
    ${__SRC_MAIN_EXE}
)

#REM: [TODO] .|. Hmmm...
#REM: [TODO, OVERVIEW] .|. Copy res to '{somewhere-exe-or-bin-build-dir}` 
add_custom_command(
    TARGET ${PROJECT_NAME}-${PROJECT_VERSION}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/main/resources $<TARGET_FILE_DIR:${PROJECT_NAME}-${PROJECT_VERSION}>
)

target_link_libraries(
    ${PROJECT_NAME}-${PROJECT_VERSION}
    PRIVATE
    ${PROJECT_NAME}.init-${PROJECT_VERSION}
    ${PROJECT_NAME}.sample_ii-${PROJECT_VERSION}
)

target_compile_options(
    ${PROJECT_NAME}-${PROJECT_VERSION}
    PRIVATE
    -Wall -Wextra -Wpedantic
)

