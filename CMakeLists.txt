cmake_minimum_required(VERSION 3.15)
project(EasySDL2)

set(CMAKE_CXX_STANDARD 17)

INCLUDE(FindPkgConfig)
INCLUDE(FetchContent)

# SDL2 - install SDL2 with 'brew install sdl2'
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDEDIR})
link_directories(${SDL2_LIBRARY_DIRS})

# GoogleTest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
# Add the demo subdirectory
add_subdirectory(sdl_application)
add_subdirectory(unit_tests)
