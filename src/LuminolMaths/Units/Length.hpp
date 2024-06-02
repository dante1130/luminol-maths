#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename Ratio>
using LengthUnitType = UnitType<UnitEnum::Length, Ratio>;

using Kilometer = LengthUnitType<std::kilo>;
using Meter = LengthUnitType<std::ratio<1>>;
using Centimeter = LengthUnitType<std::centi>;
using Millimeter = LengthUnitType<std::milli>;
using Micrometer = LengthUnitType<std::micro>;
using Nanometer = LengthUnitType<std::nano>;

template <std::floating_point T, typename U>
using Length = Unit<T, U>;

using Kilometers = Length<double, Kilometer>;
using Kilometers_f = Length<float, Kilometer>;
using Meters = Length<double, Meter>;
using Meters_f = Length<float, Meter>;
using Centimeters = Length<double, Centimeter>;
using Centimeters_f = Length<float, Centimeter>;
using Millimeters = Length<double, Millimeter>;
using Millimeters_f = Length<float, Millimeter>;
using Micrometers = Length<double, Micrometer>;
using Micrometers_f = Length<float, Micrometer>;
using Nanometers = Length<double, Nanometer>;
using Nanometers_f = Length<float, Nanometer>;

}  // namespace Luminol::Units
