add_executable(
        demo
        main.cpp
        SDL2Wrapper/SDL2Window.cpp
        SDL2Wrapper/SDL2Window.h
        SDL2Wrapper/SDL2.cpp
        SDL2Wrapper/SDL2.h
        SDL2Wrapper/SDL2Renderer.cpp
        SDL2Wrapper/SDL2Renderer.h
        NatureOfCode/Walker.cpp
        NatureOfCode/Walker.h NatureOfCode/Histogram.cpp NatureOfCode/Histogram.h NatureOfCode/IDemo.h)

target_link_libraries(demo ${SDL2_LINK_LIBRARIES})
