
#include "../sdl_application/SDL2Wrapper/SDL2.h"
#include <gtest/gtest.h>


TEST(SDL2Test, renderer_canBe_instantiated) {
    // Arrange
    auto w = new DZS::SDL2Window("test");
    auto sut = w->renderer();

    // Act

    // Assert
    EXPECT_NE((void *) NULL, (void *) sut);
}