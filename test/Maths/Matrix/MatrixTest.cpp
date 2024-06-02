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
