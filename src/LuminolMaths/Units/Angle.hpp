#pragma once

#include <numbers>
#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename Ratio>
using AngleUnitType = UnitType<UnitEnum::Angle, Ratio>;

constexpr static struct PiRatio {
    constexpr static double num = 1.0;
    constexpr static double den = std::numbers::pi / 180.0;
} PiRatio;

using Degree = AngleUnitType<std::ratio<1>>;
using Radian = AngleUnitType<RefRatio<double, PiRatio::num, PiRatio::den>>;

template <std::floating_point T, typename U>
using Angle = Unit<T, U>;

using Degrees = Angle<double, Degree>;
using Degrees_f = Angle<float, Degree>;
using Radians = Angle<double, Radian>;
using Radians_f = Angle<float, Radian>;

}  // namespace Luminol::Units
