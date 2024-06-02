#include "VectorTests.hpp"

#include <format>

#include <TestUtils.hpp>

using namespace Luminol::Maths;

namespace {

template <typename T, size_t N>
struct NormalizedTestCase {
    Vector<T, N> vector = {};
    Vector<T, N> expected = {};
};

}  // namespace

TYPED_TEST(VectorTests, Normalize) {
    {
        const auto test_cases = std::array{
            NormalizedTestCase<TypeParam, 2>{{0, 0}, {0, 0}},
            NormalizedTestCase<TypeParam, 2>{{1, 0}, {1, 0}},
            NormalizedTestCase<TypeParam, 2>{{0, 1}, {0, 1}},
            NormalizedTestCase<TypeParam, 2>{
                {1, 1},
                {
                    TypeParam{1} / std::sqrt(TypeParam{2}),
                    TypeParam{1} / std::sqrt(TypeParam{2}),
                },
            },
            NormalizedTestCase<TypeParam, 2>{
                {1, 2},
                {
                    TypeParam{1} / std::sqrt(TypeParam{5}),
                    TypeParam{2} / std::sqrt(TypeParam{5}),
                },
            },
        };

        for (const auto& [vector, expected] : test_cases) {
            EXPECT_EQ(vector.normalized(), expected) << std::format(
                "Vector {} did not normalize to expected vector.",
                to_string(vector)
            );
        }
    }

    {
        const auto test_cases = std::array{
            NormalizedTestCase<TypeParam, 3>{{0, 0, 0}, {0, 0, 0}},
            NormalizedTestCase<TypeParam, 3>{{1, 0, 0}, {1, 0, 0}},
            NormalizedTestCase<TypeParam, 3>{{0, 1, 0}, {0, 1, 0}},
            NormalizedTestCase<TypeParam, 3>{{0, 0, 1}, {0, 0, 1}},
            NormalizedTestCase<TypeParam, 3>{
                {1, 1, 1},
                {
                    TypeParam{1} / std::sqrt(TypeParam{3}),
                    TypeParam{1} / std::sqrt(TypeParam{3}),
                    TypeParam{1} / std::sqrt(TypeParam{3}),
                },
            },
            NormalizedTestCase<TypeParam, 3>{
                {1, 2, 3},
                {
                    TypeParam{1} / std::sqrt(TypeParam{14}),
                    TypeParam{2} / std::sqrt(TypeParam{14}),
                    TypeParam{3} / std::sqrt(TypeParam{14}),
                },
            },
        };

        for (const auto& [vector, expected] : test_cases) {
            EXPECT_EQ(vector.normalized(), expected) << std::format(
                "Vector {} did not normalize to expected vector.",
                to_string(vector)
            );
        }
    }

    {
        const auto test_cases = std::array{
            NormalizedTestCase<TypeParam, 4>{{0, 0, 0, 0}, {0, 0, 0, 0}},
            NormalizedTestCase<TypeParam, 4>{{1, 0, 0, 0}, {1, 0, 0, 0}},
            NormalizedTestCase<TypeParam, 4>{{0, 1, 0, 0}, {0, 1, 0, 0}},
            NormalizedTestCase<TypeParam, 4>{{0, 0, 1, 0}, {0, 0, 1, 0}},
            NormalizedTestCase<TypeParam, 4>{{0, 0, 0, 1}, {0, 0, 0, 1}},
            NormalizedTestCase<TypeParam, 4>{
                {1, 1, 1, 1},
                {
                    TypeParam{1} / std::sqrt(TypeParam{4}),
                    TypeParam{1} / std::sqrt(TypeParam{4}),
                    TypeParam{1} / std::sqrt(TypeParam{4}),
                    TypeParam{1} / std::sqrt(TypeParam{4}),
                },
            },
            NormalizedTestCase<TypeParam, 4>{
                {1, 2, 3, 4},
                {
                    TypeParam{1} / std::sqrt(TypeParam{30}),
                    TypeParam{2} / std::sqrt(TypeParam{30}),
                    TypeParam{3} / std::sqrt(TypeParam{30}),
                    TypeParam{4} / std::sqrt(TypeParam{30}),
                },
            },
        };

        for (const auto& [vector, expected] : test_cases) {
            EXPECT_EQ(vector.normalized(), expected) << std::format(
                "Vector {} did not normalize to expected vector.",
                to_string(vector)
            );
        }
    }
}
