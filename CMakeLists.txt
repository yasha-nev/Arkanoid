cmake_minimum_required(VERSION 3.25.1)

project(arcanoid VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(
    include 
    src
)

set(SRCS
    src/App.cpp
    src/MainScreen.cpp
    src/DrawableObject.cpp
    src/Player.cpp
    src/Enemy.cpp
    src/InputHandler.cpp
    src/Wall.cpp
)

set(HEADERS
    include/App.hpp
    include/MainScreen.hpp
    include/DrawableObject.hpp
    include/Player.hpp
    include/Enemy.hpp
    include/InputHandler.hpp
    include/IInputObserver.hpp
    include/Wall.hpp
)


add_compile_options(
    -Wall
    -Wextra
)

add_library(arcanoid STATIC ${SRCS} ${HEADERS})

add_executable(game main.cpp)

target_link_libraries(game arcanoid)