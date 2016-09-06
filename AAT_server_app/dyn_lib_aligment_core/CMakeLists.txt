cmake_minimum_required(VERSION 2.8)

project(AAT_aligment_core)

add_executable(AAT_core ./src/main.cpp)

install(TARGETS AAT_core DESTINATION bin)
