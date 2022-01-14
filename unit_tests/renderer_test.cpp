
#include "../sdl_application/SDL2/SDL2Renderer.h"
#include "../sdl_application/SDL2/SDL2Window.h"
#include <gtest/gtest.h>


TEST(SDL2Test, renderer_canBe_instantiated)
{
    // Arrange
    auto w = new SDL2Window("test");
    auto sut = w->renderer();

    // Act

    // Assert
    EXPECT_NE((void*)NULL, (void*)sut);
}