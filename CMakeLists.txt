cmake_minimum_required(VERSION 3.10)
project(main CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Source files
add_executable(${PROJECT_NAME} src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Find raylib
find_package(raylib REQUIRED)

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib m pthread dl)

# macOS frameworks (for raylib)
if(APPLE)
    target_link_libraries(${PROJECT_NAME}
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreAudio"
    )
endif()
