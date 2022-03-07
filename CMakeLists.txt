cmake_minimum_required(VERSION 3.15)
project(EasySDL2)

set(CMAKE_CXX_STANDARD 20)

include(ExternalProject)
ExternalProject_Add(sdl2_project
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG           main
        )
ExternalProject_Get_Property(sdl2_project SOURCE_DIR)
ExternalProject_Get_Property(sdl2_project BINARY_DIR)
set(SDL2_INCLUDE ${SOURCE_DIR}/include)
set(SDL2_BIN ${BINARY_DIR})
set(SDL2_LINK_LIBRARIES ${BINARY_DIR}/libSDL2-2.0.dylib)
include_directories(${SDL2_INCLUDE})

MESSAGE(${SDL2_LINK_LIBRARIES})





#INCLUDE(FindPkgConfig)
# SDL2 - install SDL2 with 'brew install sdl2'
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#message("**** " ${SDL2_INCLUDEDIR})
#message("**** " ${SDL2_LINK_LIBRARIES})

#link_directories(${SDL2_LIBRARY_DIRS})
# Add the demo subdirectory
add_subdirectory(DZSSDL2)
