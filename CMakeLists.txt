cmake_minimum_required(VERSION 3.10.0)
project(21game VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

if (MSVC)
    add_compile_options(/W4)
    add_compile_options(/utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_SOURCE_DIR})

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME}-${CMAKE_PROJECT_VERSION})

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_mixer REQUIRED)

add_executable(${TARGET}
    main.cpp
    info.rc

    Screen/src/display.cpp
    Screen/src/handle.cpp
    Screen/src/ui.cpp
    Screen/src/layout.cpp
    Screen/src/image.cpp
    Screen/src/text.cpp
    Screen/src/rect.cpp
    Screen/src/font.cpp

    Core/src/misc.cpp
    Core/src/game.cpp
    Core/src/card.cpp
    Core/src/player.cpp

    Core/inc/player.h
)

target_link_options(
    ${TARGET}
    PRIVATE
    "/SUBSYSTEM:WINDOWS"
)

target_link_libraries(
    ${TARGET}
    ${SDL3_LIBRARIES}
    SDL3_image::SDL3_image
    SDL3_mixer::SDL3_mixer
    SDL3_ttf::SDL3_ttf
    )
    