cmake_minimum_required(VERSION 3.25.1)

project(arkanoid VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(
    include 
    src
)

set(SRCS
    src/App.cpp
    src/Ball.cpp
    src/BaseObject.cpp
    src/CollisionManager.cpp
    src/CollisionObject.cpp
    src/Enemy.cpp
    src/GameStarter.cpp
    src/InputHandler.cpp
    src/MainScreen.cpp
    src/ObjectFactory.cpp
    src/Player.cpp
    src/Wall.cpp
)

set(HEADERS
    include/App.hpp
    include/Ball.hpp
    include/BaseObject.hpp
    include/CollisionManager.hpp
    include/CollisionObject.hpp
    include/Enemy.hpp
    include/GameStarter.hpp
    include/IInputObserver.hpp
    include/InputHandler.hpp
    include/MainScreen.hpp
    include/ObjectFactory.hpp
    include/Player.hpp
    include/Wall.hpp
)


add_compile_options(
    -Wall
    -Wextra
)

add_library(arkanoid STATIC ${SRCS} ${HEADERS})

add_executable(game main.cpp)

target_link_libraries(game arkanoid)