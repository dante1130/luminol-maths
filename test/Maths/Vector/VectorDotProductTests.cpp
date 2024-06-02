#include "VectorTests.hpp"

#include <format>

#include <TestUtils.hpp>
#include <LuminolMaths/Vector.hpp>

using namespace Luminol::Maths;

namespace {

template <typename T, size_t N>
struct DotProductTestCase {
    Vector<T, N> vector_a = {};
    Vector<T, N> vector_b = {};
    T expected = {0};
};

}  // namespace

TYPED_TEST(VectorTests, DotProduct) {
    {
        const auto test_cases = std::array{
            DotProductTestCase<TypeParam, 2>{{0, 0}, {0, 0}, 0},
            DotProductTestCase<TypeParam, 2>{{1, 0}, {0, 1}, 0},
            DotProductTestCase<TypeParam, 2>{{1, 0}, {1, 0}, 1},
            DotProductTestCase<TypeParam, 2>{{1, 1}, {1, 1}, 2},
            DotProductTestCase<TypeParam, 2>{
                Vector<TypeParam, 2>{1, 1}.normalized(),
                Vector<TypeParam, 2>{1, 1}.normalized(),
                1,
            },
            DotProductTestCase<TypeParam, 2>{
                Vector<TypeParam, 2>{1, 1}.normalized(),
                Vector<TypeParam, 2>{-1, -1}.normalized(),
                -1,
            },
            DotProductTestCase<TypeParam, 2>{
                Vector<TypeParam, 2>{1, 1}.normalized(),
                Vector<TypeParam, 2>{-1, 1}.normalized(),
                0,
            },
        };

        for (const auto& [vector_a, vector_b, expected] : test_cases) {
            Luminol::TestUtils::expect_floating_equal(
                vector_a.dot(vector_b),
                expected,
                std::format(
                    "Dot product of {} and {} is not as expected.",
                    to_string(vector_a),
                    to_string(vector_b)
                )
            );
        }
    }

    {
        const auto test_cases = std::array{
            DotProductTestCase<TypeParam, 3>{{0, 0, 0}, {0, 0, 0}, 0},
            DotProductTestCase<TypeParam, 3>{{1, 0, 0}, {0, 1, 0}, 0},
            DotProductTestCase<TypeParam, 3>{{1, 0, 0}, {1, 0, 0}, 1},
            DotProductTestCase<TypeParam, 3>{{1, 1, 1}, {1, 1, 1}, 3},
            DotProductTestCase<TypeParam, 3>{
                Vector<TypeParam, 3>{1, 1, 1}.normalized(),
                Vector<TypeParam, 3>{1, 1, 1}.normalized(),
                1,
            },
            DotProductTestCase<TypeParam, 3>{
                Vector<TypeParam, 3>{1, 1, 1}.normalized(),
                Vector<TypeParam, 3>{-1, -1, -1}.normalized(),
                -1,
            },
            DotProductTestCase<TypeParam, 3>{
                Vector<TypeParam, 3>{1, 1, 1}.normalized(),
                Vector<TypeParam, 3>{1, -1, 0}.normalized(),
                0,
            },
        };

        for (const auto& [vector_a, vector_b, expected] : test_cases) {
            Luminol::TestUtils::expect_floating_equal(
                vector_a.dot(vector_b),
                expected,
                std::format(
                    "Dot product of {} and {} is not as expected.",
                    to_string(vector_a),
                    to_string(vector_b)
                )
            );
        }
    }

    {
        const auto test_cases = std::array{
            DotProductTestCase<TypeParam, 4>{{0, 0, 0, 0}, {0, 0, 0, 0}, 0},
            DotProductTestCase<TypeParam, 4>{{1, 0, 0, 0}, {0, 1, 0, 0}, 0},
            DotProductTestCase<TypeParam, 4>{{1, 0, 0, 0}, {1, 0, 0, 0}, 1},
            DotProductTestCase<TypeParam, 4>{{1, 1, 1, 1}, {1, 1, 1, 1}, 4},
            DotProductTestCase<TypeParam, 4>{
                Vector<TypeParam, 4>{1, 1, 1, 1}.normalized(),
                Vector<TypeParam, 4>{1, 1, 1, 1}.normalized(),
                1,
            },
            DotProductTestCase<TypeParam, 4>{
                Vector<TypeParam, 4>{1, 1, 1, 1}.normalized(),
                Vector<TypeParam, 4>{-1, -1, -1, -1}.normalized(),
                -1,
            },
            DotProductTestCase<TypeParam, 4>{
                Vector<TypeParam, 4>{1, 1, 1, 1}.normalized(),
                Vector<TypeParam, 4>{-1, 1, -1, 1}.normalized(),
                0,
            },
        };

        for (const auto& [vector_a, vector_b, expected] : test_cases) {
            Luminol::TestUtils::expect_floating_equal(
                vector_a.dot(vector_b),
                expected,
                std::format(
                    "Dot product of {} and {} is not as expected.",
                    to_string(vector_a),
                    to_string(vector_b)
                )
            );
        }
    }
}
