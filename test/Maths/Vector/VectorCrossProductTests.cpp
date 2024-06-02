#include "VectorTests.hpp"

#include <format>

#include <TestUtils.hpp>
#include <LuminolMaths/Vector.hpp>

using namespace Luminol::Maths;

TYPED_TEST(VectorTests, CrossProduct) {
    struct CrossProductTestCase {
        Vector<TypeParam, 3> vector_a = {};
        Vector<TypeParam, 3> vector_b = {};
        Vector<TypeParam, 3> expected = {};
    };

    constexpr auto test_cases = std::array{
        CrossProductTestCase{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        CrossProductTestCase{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
        CrossProductTestCase{{0, 1, 0}, {1, 0, 0}, {0, 0, -1}},
        CrossProductTestCase{{1, 1, 1}, {2, 2, 2}, {0, 0, 0}},
        CrossProductTestCase{{1, 2, 3}, {0, 0, 0}, {0, 0, 0}},
        CrossProductTestCase{{-1, -2, -3}, {1, 2, 3}, {0, 0, 0}},
        CrossProductTestCase{{1, 2, 3}, {4, 5, 6}, {-3, 6, -3}},
    };

    for (const auto& [vector_a, vector_b, expected] : test_cases) {
        EXPECT_EQ(vector_a.cross(vector_b), expected) << std::format(
            "Cross product of {} and {} is not as expected.",
            to_string(vector_a),
            to_string(vector_b)
        );
    }
}
