cmake_minimum_required(VERSION 4.0)
project(chapter5)

set(CMAKE_CXX_STANDARD 23)

add_executable(chapter5 main.cpp
        playing_cards.cpp
        playing_cards.h)
