cmake_minimum_required(VERSION 3.4)


project(Programm)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    EnemyPool.cpp
    Spider.cpp
    main.cpp
)

add_executable(Programm ${SOURCES})
