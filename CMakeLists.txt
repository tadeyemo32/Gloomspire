cmake_minimum_required(VERSION 3.10)
project(main LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Option to build raylib from source (set to OFF if you want to use system-installed raylib)
option(BUILD_RAYLIB_FROM_SOURCE "Build raylib from source" ON)

if(BUILD_RAYLIB_FROM_SOURCE)
    # Add raylib from local source
    add_subdirectory(deps/raylib)
else()
    # Find installed raylib
    find_package(raylib REQUIRED)
endif()

# Define your executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    include/game.h
    include/constants.h
)

# Link against raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

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

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_SOURCE_DIR}/bin/assets
)