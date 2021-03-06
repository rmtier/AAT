cmake_minimum_required(VERSION 2.8.9)
project (TestAligmentLibrary)

enable_testing()

set (PROJECT_LINK_LIBS libAAT_core.so )
link_directories( ../dyn_lib_aligment_core/_build )

# We need thread support
find_package(Threads REQUIRED)

include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)
# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories( ../dyn_lib_aligment_core/include "${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")


FILE(GLOB_RECURSE LFiles "include/*.h")
add_custom_target(headers HEADERS ${LFiles})

FILE(GLOB_RECURSE SrcFiles "src/*.cpp")
add_custom_target(sources SOURCES ${SrcFiles})

add_executable(libtest ${SrcFiles})

target_link_libraries(libtest
    libgtest
    libgmock
)

install(TARGETS libtest DESTINATION bin)
