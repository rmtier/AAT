cmake_minimum_required(VERSION 2.8)
project(AAT_aligment_core)

include_directories(include)

FILE(GLOB_RECURSE LibFiles "include/*.h")
add_custom_target(headers SOURCES ${LibFiles})

FILE(GLOB_RECURSE SrcFiles "src/*.cpp")
add_custom_target(sources SOURCES ${SrcFiles})

add_library(AAT_core SHARED ./src/aat.cpp)

install(TARGETS AAT_core DESTINATION ./lib)
