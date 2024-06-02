#include "VectorTests.hpp"

#include <format>

#include <TestUtils.hpp>
#include <LuminolMaths/Vector.hpp>

using namespace Luminol::Maths;

namespace {

template <typename T, size_t N>
struct LengthTestCase {
    Vector<T, N> vector = {};
    T expected = {0};
};

}  // namespace

TYPED_TEST(VectorTests, Length) {
    {
        const auto test_cases = std::array{
            LengthTestCase<TypeParam, 2>{{0, 0}, 0},
            LengthTestCase<TypeParam, 2>{{1, 0}, 1},
            LengthTestCase<TypeParam, 2>{{0, 1}, 1},
            LengthTestCase<TypeParam, 2>{{1, 1}, std::sqrt(TypeParam{2})},
            LengthTestCase<TypeParam, 2>{{1, 2}, std::sqrt(TypeParam{5})},
        };

        for (const auto& [vector, expected] : test_cases) {
            Luminol::TestUtils::expect_floating_equal(
                vector.length(),
                expected,
                std::format(
                    "Vector {} length is not as expected.", to_string(vector)
                )
            );
        }
    }

    {
        const auto test_cases = std::array{
            LengthTestCase<TypeParam, 3>{{0, 0, 0}, 0},
            LengthTestCase<TypeParam, 3>{{1, 0, 0}, 1},
            LengthTestCase<TypeParam, 3>{{0, 1, 0}, 1},
            LengthTestCase<TypeParam, 3>{{0, 0, 1}, 1},
            LengthTestCase<TypeParam, 3>{{1, 1, 1}, std::sqrt(TypeParam{3})},
            LengthTestCase<TypeParam, 3>{{1, 2, 3}, std::sqrt(TypeParam{14})},
        };

        for (const auto& [vector, expected] : test_cases) {
            Luminol::TestUtils::expect_floating_equal(
                vector.length(),
                expected,
                std::format(
                    "Vector {} length is not as expected.", to_string(vector)
                )
            );
        }
    }

    {
        const auto test_cases = std::array{
            LengthTestCase<TypeParam, 4>{{0, 0, 0, 0}, 0},
            LengthTestCase<TypeParam, 4>{{1, 0, 0, 0}, 1},
            LengthTestCase<TypeParam, 4>{{0, 1, 0, 0}, 1},
            LengthTestCase<TypeParam, 4>{{0, 0, 1, 0}, 1},
            LengthTestCase<TypeParam, 4>{{0, 0, 0, 1}, 1},
            LengthTestCase<TypeParam, 4>{{1, 1, 1, 1}, std::sqrt(TypeParam{4})},
            LengthTestCase<TypeParam, 4>{
                {1, 2, 3, 4},
                std::sqrt(TypeParam{30}),
            },
        };

        for (const auto& [vector, expected] : test_cases) {
            Luminol::TestUtils::expect_floating_equal(
                vector.length(),
                expected,
                std::format(
                    "Vector {} length is not as expected.", to_string(vector)
                )
            );
        }
    }
}
