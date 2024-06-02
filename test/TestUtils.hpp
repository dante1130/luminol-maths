#pragma once

#include <gtest/gtest.h>

#include <LuminolMaths/Matrix.hpp>

namespace Luminol::TestUtils {

template <std::floating_point T>
constexpr auto expect_floating_equal(
    const T value, const T expected, const std::string_view message
) {
    if constexpr (std::is_same_v<T, float>) {
        EXPECT_FLOAT_EQ(value, expected) << message;
    } else {
        EXPECT_DOUBLE_EQ(value, expected) << message;
    }
}

template <std::floating_point T, std::size_t M, std::size_t N>
constexpr auto expect_matrix_nearly_equal(
    const Maths::Matrix<T, M, N>& value,
    const Maths::Matrix<T, M, N>& expected,
    const T epsilon,
    const std::string_view message
) {
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            EXPECT_NEAR(value[i].at(j), expected[i].at(j), epsilon) << message;

            if (::testing::Test::HasFailure()) {
                FAIL() << message;
            }
        }
    }
}

}  // namespace Luminol::TestUtils
