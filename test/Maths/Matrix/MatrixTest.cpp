#include "MatrixTestHelper.hpp"

#include <gtest/gtest.h>
#include <format>

#include <LuminolMaths/Matrix.hpp>

// Test on a 1x1 matrix that the identity test works
TEST(Matrix1x1, Identity) {
    using namespace Luminol::Maths;

    constexpr auto identity = Matrix<float, 1, 1>::identity();
    constexpr auto expected =
        Matrix<float, 1, 1>::MatrixType{std::array{std::array{1.0f}}};

    EXPECT_TRUE(identity == expected) << std::format(
        "Matrix1x1 identity failed to produce the expected result.\n"
        "Identity: {}\nVS\nExpected: {}",
        MatrixTestHelper::convert_matrix_to_string<float, 1, 1>(identity),
        MatrixTestHelper::convert_matrix_to_string<float, 1, 1>(expected)
    );
}

// Test on a 4x4 matrix that the identity test works
TEST(Matrix4x4, Identity) {
    using namespace Luminol::Maths;

    constexpr auto identity = Matrix4x4f::identity();
    constexpr auto expected = Matrix4x4f{std::array{
        std::array{1.0f, 0.0f, 0.0f, 0.0f},
        std::array{0.0f, 1.0f, 0.0f, 0.0f},
        std::array{0.0f, 0.0f, 1.0f, 0.0f},
        std::array{0.0f, 0.0f, 0.0f, 1.0f},
    }};

    EXPECT_TRUE(identity == expected) << std::format(
        "Matrix4x4 identity failed to produce the expected result.\n"
        "Identity: {}\nVS\nExpected: {}",
        MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(identity),
        MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(expected)
    );
}

TEST(Matrix4x4, Cofactor) {
    using namespace Luminol::Maths;

    constexpr auto matrix = Matrix4x4f{std::array{
        std::array{3.0f, 0.0f, 2.0f, -1.0f},
        std::array{1.0f, 2.0f, 0.0f, -2.0f},
        std::array{4.0f, 0.0f, 6.0f, -3.0f},
        std::array{5.0f, 0.0f, 2.0f, 0.0f},
    }};

    {
        const auto cofactor = matrix.cofactor();

        constexpr auto expected = Matrix4x4f{std::array{
            std::array{12.0f, -50.0f, -30.0f, -44.0f},
            std::array{0.0f, 10.0f, 0.0f, 0.0f},
            std::array{-4.0f, 10.0f, 10.0f, 8.0f},
            std::array{0.0f, 20.0f, 10.0f, 20.0f},
        }};

        EXPECT_TRUE(cofactor == expected) << std::format(
            "Matrix4x4 cofactor failed to produce the expected result.\n"
            "Cofactor: {}\nVS\nExpected: {}",
            MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(cofactor),
            MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(expected)
        );
    }
}

TEST(Matrix4x4, Determinant) {
    using namespace Luminol::Maths;

    constexpr auto matrix = Matrix4x4f{std::array{
        std::array{3.0f, 0.0f, 2.0f, -1.0f},
        std::array{1.0f, 2.0f, 0.0f, -2.0f},
        std::array{4.0f, 0.0f, 6.0f, -3.0f},
        std::array{5.0f, 0.0f, 2.0f, 0.0f},
    }};

    {
        const auto determinant = matrix.determinant();
        constexpr auto expected = 20.0f;

        EXPECT_EQ(determinant, expected) << std::format(
            "Matrix4x4 determinant failed to "
            "produce the expected result.\n"
            "Determinant: {}\nVS\nExpected: {}",
            determinant,
            expected
        );
    }
}

TEST(Matrix4x4, Adjugate) {
    using namespace Luminol::Maths;

    constexpr auto matrix = Matrix4x4f{std::array{
        std::array{3.0f, 0.0f, 2.0f, -1.0f},
        std::array{1.0f, 2.0f, 0.0f, -2.0f},
        std::array{4.0f, 0.0f, 6.0f, -3.0f},
        std::array{5.0f, 0.0f, 2.0f, 0.0f},
    }};

    {
        const auto adjugate = matrix.adjugate();

        constexpr auto expected = Matrix4x4f{std::array{
            std::array{12.0f, 0.0f, -4.0f, 0.0f},
            std::array{-50.0f, 10.0f, 10.0f, 20.0f},
            std::array{-30.0f, 0.0f, 10.0f, 10.0f},
            std::array{-44.0f, 0.0f, 8.0f, 20.0f},
        }};

        EXPECT_TRUE(adjugate == expected) << std::format(
            "Matrix4x4 adjugate failed to produce the expected result.\n"
            "Adjugate: {}\nVS\nExpected: {}",
            MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(adjugate),
            MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(expected)
        );
    }
}

TEST(Matrix4x4, Inverse) {
    using namespace Luminol::Maths;

    constexpr auto matrix = Matrix4x4f{std::array{
        std::array{3.0f, 0.0f, 2.0f, -1.0f},
        std::array{1.0f, 2.0f, 0.0f, -2.0f},
        std::array{4.0f, 0.0f, 6.0f, -3.0f},
        std::array{5.0f, 0.0f, 2.0f, 0.0f},
    }};

    {
        const auto inverse = matrix.inverse();

        constexpr auto expected = Matrix4x4f{std::array{
            std::array{0.6f, 0.0f, -0.2f, 0.0f},
            std::array{-2.5f, 0.5f, 0.5f, 1.0f},
            std::array{-1.5f, 0.0f, 0.5f, 0.5f},
            std::array{-2.2f, 0.0f, 0.4f, 1.0f},
        }};

        EXPECT_TRUE(inverse == expected) << std::format(
            "Matrix4x4 inverse failed to produce the expected result.\n"
            "Inverse: {}\nVS\nExpected: {}",
            MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(inverse),
            MatrixTestHelper::convert_matrix_to_string<float, 4, 4>(expected)
        );
    }
}
