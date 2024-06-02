#pragma once

#include <gtest/gtest.h>

#include <format>

#include <TestUtils.hpp>
#include <LuminolMaths/Units/Angle.hpp>

namespace Luminol::Units {

template <std::floating_point T>
class AngleTests : public ::testing::Test {
public:
    constexpr static auto test_conversion(
        const Angle<T, Radian> radians, const Angle<T, Degree> degrees
    ) {
        test_radians_to_degrees(radians, degrees);
        test_degrees_to_radians(degrees, radians);
    }

private:
    constexpr static auto test_radians_to_degrees(
        const Angle<T, Radian> radians, const Angle<T, Degree> expected_degrees
    ) {
        const auto degrees = radians.template as<Degree>();

        TestUtils::expect_floating_equal(
            degrees.get_value(),
            expected_degrees.get_value(),
            std::format(
                "Converting radians of {} to degrees failed to produce "
                "the expected result in degrees.\n",
                radians.get_value()
            )
        );
    }

    constexpr static auto test_degrees_to_radians(
        const Angle<T, Degree> degrees, const Angle<T, Radian> expected_radians
    ) {
        const auto radians = degrees.template as<Radian>();

        TestUtils::expect_floating_equal(
            radians.get_value(),
            expected_radians.get_value(),
            std::format(
                "Converting degrees of {} to radians failed to produce "
                "the expected result in radians.\n",
                degrees.get_value()
            )
        );
    }
};

}  // namespace Luminol::Units

using AngleStorageTypes = ::testing::Types<float, double>;

TYPED_TEST_SUITE(AngleTests, AngleStorageTypes);
