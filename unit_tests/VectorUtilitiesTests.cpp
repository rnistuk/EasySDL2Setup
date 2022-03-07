#include "../sdl_application/NatureOfCode/VectorUtilities.h"
#include <gtest/gtest.h>
#include <vector>

TEST(VectorUtilitiesTest, Vector_canAddVectorsOfSameSizeUsingPlusOperator) {
    // Arrange
    auto v0 = std::vector{1,2,3};
    auto v1 = std::vector{3,2,1};
    auto accepted = std::vector{4,4,4};

    // Act
    auto actual = v0 + v1;

    // Assert
    EXPECT_EQ(accepted.size(), actual.size());
    for(size_t i{0}; i<accepted.size(); ++i)
    {
        auto a{accepted[i]};
        auto b{actual[i]};
        EXPECT_EQ(a, b);
    }
}

TEST(VectorUtilitiesTest, Vector_canSubtractVectorsOfSameSizeUsingSubtractOperator) {
    // Arrange
    auto v0 = std::vector{4, 4, 4};
    auto v1 = std::vector{1, 2, 3};
    auto accepted = std::vector{3, 2, 1};

    // Act
    auto actual = v0 - v1;

    // Assert
    EXPECT_EQ(accepted.size(), actual.size());
    for(size_t i{0}; i<accepted.size(); ++i)
    {
        auto a{accepted[i]};
        auto b{accepted[i]};
        EXPECT_EQ(a, b);
    }
}

TEST(VectorUtilitiesTest, Vector_canAddVectorsOfSameSizeUsingAddMethod) {
    // Arrange
    auto v0 = std::vector{4, 4, 4};
    auto v1 = std::vector{1, 2, 3};
    auto accepted = std::vector{5, 5, 5};

    // Act
    auto actual = add(v0, v1);

    // Assert
    EXPECT_EQ(accepted.size(), actual.size());

    for(size_t i{0}; i<accepted.size(); ++i)
    {
        auto a{accepted[i]};
        auto b{accepted[i]};
        EXPECT_EQ(a, b);
    }
}

TEST(VectorUtilitiesTest, Vector_canScaleNumberTimesVectorUsingMultOperator) {
    // Arrange
    auto c = 2;
    auto v0 = std::vector{0, 1, 3};
    auto accepted = std::vector{0, 2, 6};

    // Act
    auto actual = c * v0;

    // Assert
    EXPECT_EQ(v0.size(), actual.size());

    for(size_t i{0}; i<accepted.size(); ++i)
    {
        auto a{accepted[i]};
        auto b{accepted[i]};
        EXPECT_EQ(a, b);
    }
}

TEST(VectorUtilitiesTest, Vector_canScaleVectorTimesNumberUsingMultOperator) {
    // Arrange
    auto c = 2.0f;
    auto v0 = std::vector{0.0f, 1.0f, 3.0f};
    auto accepted = std::vector{0.0f, 2.0f, 6.0f};

    // Act
    auto actual = v0 * c;

    // Assert
    EXPECT_EQ(v0.size(), actual.size());

    for(size_t i{0}; i<accepted.size(); ++i)
    {
        auto a{accepted[i]};
        auto b{accepted[i]};
        EXPECT_EQ(a, b);
    }
}

TEST(VectorUtilitiesTest, Vector_canScaleVectorByNumberUsingdivisionOperator) {
    // Arrange
    auto c = 2.0f;
    auto v0 = std::vector{0.0f, 1.0f, 4.0f};
    auto accepted = std::vector{0.0f, 0.5f, 2.0f};

    // Act
    auto actual = v0 / c;

    // Assert
    EXPECT_EQ(v0.size(), actual.size());

    for(size_t i{0}; i<accepted.size(); ++i)
    {
        auto a{accepted[i]};
        auto b{accepted[i]};
        EXPECT_EQ(a, b);
    }
}

TEST(VectorUtilitiesTest, Vector_magFunctionCorrectlyReportsMagnitude)
{
    // Arrange
    auto sut{std::vector{0.0f, 1.0f, 4.0f}};

    // Act
    auto accepted{std::sqrt(0.0f * 0.0f + 1.0f * 1.0f + 4.0f * 4.0f)};
    auto actual {mag(sut)};

    // Assert
    EXPECT_EQ(accepted, actual);
}

TEST(VectorUtilitiesTest, Vector_setMagFunctionCorrectlySetsMagnitude)
{
    // Arrange
    auto sut{std::vector{0.0f, 1.0f, 4.0f}};

    // Act
    auto accepted{10.0f};
    sut = setMag(sut, 10.0f);
    auto actual {mag(sut)};

    // Assert
    EXPECT_NEAR(accepted, actual, 0.00001);

}

TEST(VectorUtilitiesTest, Vector_normalizeFunctionCorrectlyNormalizes)
{
    // Arrange
    auto sut{std::vector{1.0f, 1.0f, 4.0f}};

    // Act
    std::vector<float> accepted{setMag(sut,1.0f)};
    std::vector<float> actual{normalize(sut)};

    // Assert
    EXPECT_NEAR(mag(accepted), mag(actual), 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_limitFunctionCorrectlyResizes)
{
    // Arrange
    auto sut{std::vector{1.0f, 1.0f, 4.0f}};

    // Act
    std::vector<float> accepted{setMag(sut,200.0f)};
    std::vector<float> actual{limit(sut, 200.0f)};

    // Assert
    EXPECT_NEAR(mag(accepted), mag(actual), 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_headingFunctionCorrectlyReturnsHeadingInRadiansOfATwoDVector)
{
    // Arrange
    // Act
    // Assert
    EXPECT_NEAR(heading(std::vector{0.0f, 0.0f}), 0.0, 0.00001f);
    EXPECT_NEAR(heading(std::vector{1.0f, 1.0f}), (double)(M_PI/4.0), 0.00001f);
    EXPECT_NEAR(heading(std::vector{1.0f, -1.0f}), (double)(-M_PI/4.0), 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_rotateFunctionCorrectlyChangesTheHeadingOfATwoDZeroVector)
{
    // Arrange
    auto zero{std::vector{0.0f, 0.0f}};

    // Act
    auto zeroRotated {rotate(zero, (double)(M_PI/4.0))};
    // Assert
    EXPECT_NEAR( zeroRotated[0], 0.0, 0.00001f);
    EXPECT_NEAR( zeroRotated[1], 0.0, 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_rotateFunctionCorrectlyChangesTheHeadingOfATwoDNonZeroVector)
{
    // Arrange
    auto sut{std::vector{1.0f, 0.0f}};

    // Act
    auto actual {rotate(sut, (float)(M_PI/4.0f))};
    auto accepted {std::vector<float>{std::sqrt(2.0f)/2.0f, std::sqrt(2.0f)/2.0f}};

    // Assert
    EXPECT_NEAR( actual[0], accepted[0], 0.00001f);
    EXPECT_NEAR( actual[1], accepted[1], 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_distFunctionCorrectlyCalculatesDistanceBetweenTwoVectors)
{
    // Arrange
    auto sut_A{std::vector{0.0f, 0.0f}};
    auto sut_B{std::vector{1.0f, 1.0f}};

    // Act
    auto actual {dist(sut_A, sut_B)};
    auto accepted {std::sqrt(2.0f)};

    // Assert
    EXPECT_NEAR( actual, accepted, 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_angleBetweenFunctionCorrectlyCalculatesAngleBetweenTwoVectors)
{
    // Arrange
    auto sut_A{std::vector{0.0f, 0.0f}};
    auto sut_B{std::vector{1.0f, 1.0f}};

    // Act
    auto actual { angleBetween(sut_A, sut_B) };
    auto accepted {std::sqrt(2.0f)};

    // Assert
    EXPECT_NEAR( actual, accepted, 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_dotProductFunction)
{
    // Arrange
    auto sut_A{std::vector{3.0f, 2.0f, 1.0f}};
    auto sut_B{std::vector{1.0f, 2.0f, 3.0f}};

    // Act
    auto actual { dot(sut_A, sut_B) };
    auto accepted {sut_A[0] * sut_B[0] + sut_A[1] * sut_B[1] + sut_A[2] * sut_B[2]};

    // Assert
    EXPECT_NEAR( actual, accepted, 0.00001f);
}

TEST(VectorUtilitiesTest, Vector_crossProductFunction)
{
    // Arrange
    auto A{std::vector{3.0f, 2.0f, 1.0f}};
    auto B{std::vector{1.0f, 2.0f, 3.0f}};

    // Act
    auto actual { cross(A, B) };
    auto accepted {std::vector{
        A[1]*B[2] - A[2] * B[1]
        , A[2] * B[0] - A[0] * B[2]
        , A[0] * B[1] - A[1] * B[2]}};

    // Assert
    EXPECT_NEAR( actual[0], accepted[0], 0.00001f);
    EXPECT_NEAR( actual[1], accepted[1], 0.00001f);
    EXPECT_NEAR( actual[2], accepted[2], 0.00001f);
}
