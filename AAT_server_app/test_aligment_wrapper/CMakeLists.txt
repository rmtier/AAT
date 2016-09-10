cmake_minimum_required(VERSION 2.8.9)
project (TestAligmentLibrary)

set (PROJECT_LINK_LIBS libAAT_core.so )
link_directories( ../dyn_lib_aligment_core/_build )

include_directories(../dyn_lib_aligment_core/include include)

FILE(GLOB_RECURSE LFiles "include/*.h")
add_custom_target(headers SOURCES ${LFiles})

add_executable(libtest ./src/main.cpp)

target_link_libraries(libtest AAT_core.so)
