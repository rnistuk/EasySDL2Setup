#include "../sdl_application/SDL2/SDL2Window.h"
#include <gtest/gtest.h>

TEST(WindowTest, SDL2Window_canBe_constructed) {
    // Arrange
    auto sut = new SDL2Window("");
    // Act

    // Assert
    EXPECT_NE((void*)NULL, (void*)sut);
}

TEST(WindowTest, SDL2Window_isValid_window) {
    // Arrange
    auto sut = new SDL2Window("title");

    // Act

    // Assert
    EXPECT_NE((void*)nullptr, (void*)sut);
    EXPECT_EQ("title", sut->title());
    EXPECT_EQ(640, sut->width());
    EXPECT_EQ(480, sut->height());
    EXPECT_NE(nullptr, sut->renderer());
}

