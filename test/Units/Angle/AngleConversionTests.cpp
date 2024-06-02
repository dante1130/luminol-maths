#include "AngleTests.hpp"

#include <array>
#include <numbers>

using namespace Luminol::Units;

TYPED_TEST(AngleTests, AngleConversions) {
    struct AngleConversion {
        Angle<TypeParam, Radian> radians;
        Angle<TypeParam, Degree> degrees;
    };

    constexpr auto conversions_to_test = std::array{
        AngleConversion{
            Angle<TypeParam, Radian>{std::numbers::pi_v<TypeParam>},
            Angle<TypeParam, Degree>{180},
        },
        AngleConversion{
            Angle<TypeParam, Radian>{std::numbers::pi_v<TypeParam> / 2},
            Angle<TypeParam, Degree>{90},
        },
        AngleConversion{
            Angle<TypeParam, Radian>{std::numbers::pi_v<TypeParam> * 2},
            Angle<TypeParam, Degree>{360},
        },
        AngleConversion{
            Angle<TypeParam, Radian>{std::numbers::pi_v<TypeParam> / 4},
            Angle<TypeParam, Degree>{45},
        },
        AngleConversion{
            Angle<TypeParam, Radian>{std::numbers::pi_v<TypeParam> * 3 / 4},
            Angle<TypeParam, Degree>{135},
        },
    };

    for (const auto& conversion : conversions_to_test) {
        this->test_conversion(conversion.radians, conversion.degrees);
    }
}
