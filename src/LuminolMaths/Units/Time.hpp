#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename Ratio>
using TimeUnitType = UnitType<UnitEnum::Time, Ratio>;

constexpr static auto hour_ratio = 3600;
constexpr static auto minute_ratio = 60;

using Hour = TimeUnitType<std::ratio<hour_ratio>>;
using Minute = TimeUnitType<std::ratio<minute_ratio>>;
using Second = TimeUnitType<std::ratio<1>>;
using Millisecond = TimeUnitType<std::milli>;
using Microsecond = TimeUnitType<std::micro>;
using Nanosecond = TimeUnitType<std::nano>;

template <std::floating_point T, typename U>
using Time = Unit<T, U>;

using Hours = Time<double, Hour>;
using Hours_f = Time<float, Hour>;
using Minutes = Time<double, Minute>;
using Minutes_f = Time<float, Minute>;
using Seconds = Time<double, Second>;
using Seconds_f = Time<float, Second>;
using Milliseconds = Time<double, Millisecond>;
using Milliseconds_f = Time<float, Millisecond>;
using Microseconds = Time<double, Microsecond>;
using Microseconds_f = Time<float, Microsecond>;
using Nanoseconds = Time<double, Nanosecond>;
using Nanoseconds_f = Time<float, Nanosecond>;

}  // namespace Luminol::Units
