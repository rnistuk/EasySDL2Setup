cmake_minimum_required(VERSION 3.15)
project(EasySDL2)

set(CMAKE_CXX_STANDARD 23)

INCLUDE(FindPkgConfig)
INCLUDE(FetchContent)
INCLUDE(ExternalProject)

# SDL2 - install SDL2 with 'brew install sdl2'
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# SDL2_image - install SDL2_image with 'brew install sdl2_image'
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

# SDL2_ttl - install SDL2 with 'brew install sdl2_ttf'
#PKG_SEARCH_MODULE(SDL2_TTF REQUIRED)
# find_package(SDL2_ttf REQUIRED)



#include_directories(${SDL2_INCLUDEDIR}  ${SDL2TTL_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY_DIRS}  ${SDL2TTL_LIBRARIES})

# GoogleTest
#FetchContent_Declare( googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip )
#FetchContent_MakeAvailable(googletest)

# FetchContent_Declare(sdl2 GIT_REPOSITORY "https://github.com/SDL-mirror/SDL.git" GIT_TAG "release-2.0.10" )
# FetchContent_MakeAvailable(sdl2)

# Add the demo subdirectory
#add_subdirectory(sdl_application)
#add_subdirectory(unit_tests)
