#include "../sdl_application/SDL2Wrapper/SDL2.h"
#include <gtest/gtest.h>
#include <SDL2/SDL.h>

TEST(SDL2Test, SDL2_canBe_instantiated) {
    // Arrange
    auto sut = new  DZS::SDL2();
    // Act

    // Assert
    EXPECT_NE((void *) NULL, (void *) sut);
}

TEST(SDL2Test, SDL2_canBe_initialized) {
    // Arrange
    auto sut = new DZS::SDL2();

    // Act
    auto actual = SDL_WasInit(SDL_INIT_EVERYTHING);

    // Assert
    EXPECT_EQ(SDL_INIT_EVERYTHING, actual);
}

TEST(SDL2Test, SDL2_cleansUp_whenDeleted) {
    // Arrange
    auto sut = new DZS::SDL2();
    delete sut;

    // Act
    auto actual = SDL_WasInit(SDL_INIT_EVERYTHING);

    // Assert
    EXPECT_EQ(0, actual);
}

TEST(SDL2Test, SDL2_createsWindow) {
    // Arrange
    auto title = "title";
    auto sut = new DZS::SDL2();
    auto actual = sut->createWindow();

    // Act

    // Assert
    EXPECT_NE(nullptr, actual);
    EXPECT_EQ(title, actual->title());
}


