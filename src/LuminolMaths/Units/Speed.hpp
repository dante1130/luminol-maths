#pragma once

#include <ratio>

#include <LuminolMaths/Units/Length.hpp>
#include <LuminolMaths/Units/Time.hpp>
#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename LengthU, typename TimeU>
using SpeedUnitType = UnitType<
    UnitEnum::Speed,
    std::ratio_divide<typename LengthU::ratio, typename TimeU::ratio>>;

using KilometerPerHour = SpeedUnitType<Kilometer, Hour>;
using MeterPerHour = SpeedUnitType<Meter, Hour>;
using CentimeterPerHour = SpeedUnitType<Centimeter, Hour>;
using MillimeterPerHour = SpeedUnitType<Millimeter, Hour>;
using MicrometerPerHour = SpeedUnitType<Micrometer, Hour>;
using NanometerPerHour = SpeedUnitType<Nanometer, Hour>;

using KilometerPerMinute = SpeedUnitType<Kilometer, Minute>;
using MeterPerMinute = SpeedUnitType<Meter, Minute>;
using CentimeterPerMinute = SpeedUnitType<Centimeter, Minute>;
using MillimeterPerMinute = SpeedUnitType<Millimeter, Minute>;
using MicrometerPerMinute = SpeedUnitType<Micrometer, Minute>;
using NanometerPerMinute = SpeedUnitType<Nanometer, Minute>;

using KilometerPerSecond = SpeedUnitType<Kilometer, Second>;
using MeterPerSecond = SpeedUnitType<Meter, Second>;
using CentimeterPerSecond = SpeedUnitType<Centimeter, Second>;
using MillimeterPerSecond = SpeedUnitType<Millimeter, Second>;
using MicrometerPerSecond = SpeedUnitType<Micrometer, Second>;
using NanometerPerSecond = SpeedUnitType<Nanometer, Second>;

template <std::floating_point T, typename U>
using Speed = Unit<T, U>;

template <std::floating_point T, typename LengthU, typename TimeU>
    requires(LengthU::type == UnitEnum::Length && TimeU::type == UnitEnum::Time)
constexpr auto operator/(
    const Length<T, LengthU>& length, const Time<T, TimeU>& time
) -> Speed<T, SpeedUnitType<LengthU, TimeU>> {
    constexpr auto length_ratio = static_cast<T>(LengthU::ratio::num) /
                                  static_cast<T>(LengthU::ratio::den);
    constexpr auto time_ratio =
        static_cast<T>(TimeU::ratio::num) / static_cast<T>(TimeU::ratio::den);

    static_assert(length_ratio != 0);
    static_assert(time_ratio != 0);

    constexpr auto speed_ratio = length_ratio / time_ratio;

    return Speed<T, SpeedUnitType<LengthU, TimeU>>{
        length.get_value() / time.get_value() * speed_ratio,
    };
}

using KilometersPerHour = Speed<double, KilometerPerHour>;
using KilometersPerHour_f = Speed<float, KilometerPerHour>;
using MetersPerHour = Speed<double, MeterPerHour>;
using MetersPerHour_f = Speed<float, MeterPerHour>;
using CentimetersPerHour = Speed<double, CentimeterPerHour>;
using CentimetersPerHour_f = Speed<float, CentimeterPerHour>;
using MillimetersPerHour = Speed<double, MillimeterPerHour>;
using MillimetersPerHour_f = Speed<float, MillimeterPerHour>;
using MicrometersPerHour = Speed<double, MicrometerPerHour>;
using MicrometersPerHour_f = Speed<float, MicrometerPerHour>;
using NanometersPerHour = Speed<double, NanometerPerHour>;
using NanometersPerHour_f = Speed<float, NanometerPerHour>;

using KilometersPerMinute = Speed<double, KilometerPerMinute>;
using KilometersPerMinute_f = Speed<float, KilometerPerMinute>;
using MetersPerMinute = Speed<double, MeterPerMinute>;
using MetersPerMinute_f = Speed<float, MeterPerMinute>;
using CentimetersPerMinute = Speed<double, CentimeterPerMinute>;
using CentimetersPerMinute_f = Speed<float, CentimeterPerMinute>;
using MillimetersPerMinute = Speed<double, MillimeterPerMinute>;
using MillimetersPerMinute_f = Speed<float, MillimeterPerMinute>;
using MicrometersPerMinute = Speed<double, MicrometerPerMinute>;
using MicrometersPerMinute_f = Speed<float, MicrometerPerMinute>;
using NanometersPerMinute = Speed<double, NanometerPerMinute>;
using NanometersPerMinute_f = Speed<float, NanometerPerMinute>;

using KilometersPerSecond = Speed<double, KilometerPerSecond>;
using KilometersPerSecond_f = Speed<float, KilometerPerSecond>;
using MetersPerSecond = Speed<double, MeterPerSecond>;
using MetersPerSecond_f = Speed<float, MeterPerSecond>;
using CentimetersPerSecond = Speed<double, CentimeterPerSecond>;
using CentimetersPerSecond_f = Speed<float, CentimeterPerSecond>;
using MillimetersPerSecond = Speed<double, MillimeterPerSecond>;
using MillimetersPerSecond_f = Speed<float, MillimeterPerSecond>;
using MicrometersPerSecond = Speed<double, MicrometerPerSecond>;
using MicrometersPerSecond_f = Speed<float, MicrometerPerSecond>;
using NanometersPerSecond = Speed<double, NanometerPerSecond>;
using NanometersPerSecond_f = Speed<float, NanometerPerSecond>;

}  // namespace Luminol::Units
