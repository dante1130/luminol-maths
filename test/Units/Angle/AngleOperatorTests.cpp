#include "AngleTests.hpp"

using namespace Luminol::Units;

namespace {

template <std::floating_point T>
constexpr auto test_arithmetic_operators() -> void {
    constexpr auto degrees = Angle<T, Degree>(180);
    constexpr auto radians = Angle<T, Radian>(std::numbers::pi_v<T> / 2);

    constexpr auto sum = degrees + radians;
    constexpr auto difference = degrees - radians;

    constexpr auto expected_sum = Angle<T, Degree>(270);
    static_assert(sum == expected_sum);

    constexpr auto expected_difference = Angle<T, Degree>(90);
    static_assert(difference == expected_difference);
}

template <std::floating_point T>
constexpr auto test_arithmetic_assignment_operators() -> void {
    constexpr auto initial_degrees = Angle<T, Degree>(90);
    auto degrees = initial_degrees;

    constexpr auto radians_to_add = Angle<T, Radian>(std::numbers::pi_v<T>);
    degrees += radians_to_add;

    constexpr auto expected_sum = Angle<T, Degree>(270);
    EXPECT_TRUE(degrees == expected_sum);

    constexpr auto radians_to_subtract =
        Angle<T, Radian>(std::numbers::pi_v<T> * 2);
    degrees -= radians_to_subtract;

    constexpr auto expected_difference = Angle<T, Degree>(-90);
    EXPECT_TRUE(degrees == expected_difference);
}

template <std::floating_point T>
constexpr auto test_arithmetic_scalar_operators() -> void {
    constexpr auto angle = Angle<T, Degree>(90);
    constexpr auto scalar = 2;

    constexpr auto product = angle * scalar;
    constexpr auto quotient = angle / scalar;

    constexpr auto expected_product = Angle<T, Degree>(180);
    static_assert(product == expected_product);

    constexpr auto expected_quotient = Angle<T, Degree>(45);
    static_assert(quotient == expected_quotient);
}

template <std::floating_point T>
constexpr auto test_comparison_operators() -> void {
    constexpr auto degrees = Angle<T, Degree>(90);
    constexpr auto radians = Angle<T, Radian>(std::numbers::pi_v<T>);

    static_assert(degrees != radians);
    static_assert(degrees < radians);
    static_assert(degrees <= radians);
}

template <std::floating_point T>
constexpr auto test_negation_operator() -> void {
    constexpr auto angle = Angle<T, Degree>(90);

    constexpr auto negation = -angle;

    constexpr auto expected_negation = Angle<T, Degree>(-90);
    static_assert(negation == expected_negation);
}

}  // namespace

TYPED_TEST(AngleTests, Operators) {
    test_arithmetic_operators<TypeParam>();
    test_arithmetic_assignment_operators<TypeParam>();
    test_arithmetic_scalar_operators<TypeParam>();
    test_comparison_operators<TypeParam>();
    test_negation_operator<TypeParam>();
}
