add_executable(
        demo
        main.cpp
        SDL2Wrapper/SDL2Window.cpp
        SDL2Wrapper/SDL2Window.h
        SDL2Wrapper/SDL2.cpp
        SDL2Wrapper/SDL2.h
        SDL2Wrapper/SDL2Renderer.cpp
        SDL2Wrapper/SDL2Renderer.h
)

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

target_link_libraries(demo ${SDL2_LINK_LIBRARIES} ${SDLTTF_LIBRARY})
