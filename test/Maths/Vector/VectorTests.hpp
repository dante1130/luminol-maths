#pragma once

#include <gtest/gtest.h>

#include <LuminolMaths/Vector.hpp>

namespace Luminol::Maths {

template <std::floating_point T>
struct VectorTests : public ::testing::Test {};

using VectorStorageTypes = ::testing::Types<float, double>;

TYPED_TEST_SUITE(VectorTests, VectorStorageTypes);

template <typename T, size_t N>
constexpr auto operator<<(
    std::ostream& output_stream, const Vector<T, N>& vector
) -> std::ostream& {
    output_stream << "{";

    for (size_t i = 0; i < N - 1; ++i) {
        output_stream << vector[i] << ", ";
    }

    output_stream << vector[N - 1] << "}";

    return output_stream;
}

template <typename T, size_t N>
constexpr auto to_string(const Vector<T, N>& vector) -> std::string {
    return (std::ostringstream{} << vector).str();
}

}  // namespace Luminol::Maths
