cmake_minimum_required(VERSION 3.10)
project(main LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Option to build raylib from source
option(BUILD_RAYLIB_FROM_SOURCE "Build raylib from source" ON)

# Automatically collect all .cpp and .c files in src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

# Include header directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add raylib
if(BUILD_RAYLIB_FROM_SOURCE)
    add_subdirectory(deps/raylib)
else()
    find_package(raylib REQUIRED)
endif()

# Define executable using all source files
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link against raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# macOS frameworks
if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreAudio"
        "-framework CoreVideo"
    )
endif()

# Copy assets after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)
