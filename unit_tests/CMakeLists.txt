enable_testing()

add_executable(
        tests
        window_test.cpp
        sdl_test.cpp
        ../sdl_application/SDL2Wrapper/SDL2.cpp
        ../sdl_application/SDL2Wrapper/SDL2.h
        ../sdl_application/SDL2Wrapper/SDL2Renderer.cpp
        ../sdl_application/SDL2Wrapper/SDL2Renderer.h
        renderer_test.cpp
)

target_link_libraries(
        tests
        gtest_main
        ${SDL2_LINK_LIBRARIES}
)

include(GoogleTest)
gtest_discover_tests(tests)
