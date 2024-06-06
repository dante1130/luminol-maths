#pragma once

#include <ratio>

#include <LuminolMaths/Units/Length.hpp>
#include <LuminolMaths/Units/Time.hpp>
#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename LengthU, typename TimeU>
using VelocityUnitType = UnitType<
    UnitEnum::Velocity,
    std::ratio_divide<typename LengthU::ratio, typename TimeU::ratio>>;

using KilometerPerHour = VelocityUnitType<Kilometer, Hour>;
using MeterPerHour = VelocityUnitType<Meter, Hour>;
using CentimeterPerHour = VelocityUnitType<Centimeter, Hour>;
using MillimeterPerHour = VelocityUnitType<Millimeter, Hour>;
using MicrometerPerHour = VelocityUnitType<Micrometer, Hour>;
using NanometerPerHour = VelocityUnitType<Nanometer, Hour>;

using KilometerPerMinute = VelocityUnitType<Kilometer, Minute>;
using MeterPerMinute = VelocityUnitType<Meter, Minute>;
using CentimeterPerMinute = VelocityUnitType<Centimeter, Minute>;
using MillimeterPerMinute = VelocityUnitType<Millimeter, Minute>;
using MicrometerPerMinute = VelocityUnitType<Micrometer, Minute>;
using NanometerPerMinute = VelocityUnitType<Nanometer, Minute>;

using KilometerPerSecond = VelocityUnitType<Kilometer, Second>;
using MeterPerSecond = VelocityUnitType<Meter, Second>;
using CentimeterPerSecond = VelocityUnitType<Centimeter, Second>;
using MillimeterPerSecond = VelocityUnitType<Millimeter, Second>;
using MicrometerPerSecond = VelocityUnitType<Micrometer, Second>;
using NanometerPerSecond = VelocityUnitType<Nanometer, Second>;

template <std::floating_point T, typename U>
using Velocity = Unit<T, U>;

template <std::floating_point T, typename LengthU, typename TimeU>
    requires(LengthU::type == UnitEnum::Length && TimeU::type == UnitEnum::Time)
constexpr auto operator/(
    const Length<T, LengthU>& length, const Time<T, TimeU>& time
) -> Velocity<T, VelocityUnitType<LengthU, TimeU>> {
    constexpr auto length_ratio = static_cast<T>(LengthU::ratio::num) /
                                  static_cast<T>(LengthU::ratio::den);
    constexpr auto time_ratio =
        static_cast<T>(TimeU::ratio::num) / static_cast<T>(TimeU::ratio::den);

    static_assert(length_ratio != 0);
    static_assert(time_ratio != 0);

    constexpr auto velocity_ratio = length_ratio / time_ratio;

    return Velocity<T, VelocityUnitType<LengthU, TimeU>>{
        length.get_value() / time.get_value() * velocity_ratio,
    };
}

using KilometersPerHour = Velocity<double, KilometerPerHour>;
using KilometersPerHour_f = Velocity<float, KilometerPerHour>;
using MetersPerHour = Velocity<double, MeterPerHour>;
using MetersPerHour_f = Velocity<float, MeterPerHour>;
using CentimetersPerHour = Velocity<double, CentimeterPerHour>;
using CentimetersPerHour_f = Velocity<float, CentimeterPerHour>;
using MillimetersPerHour = Velocity<double, MillimeterPerHour>;
using MillimetersPerHour_f = Velocity<float, MillimeterPerHour>;
using MicrometersPerHour = Velocity<double, MicrometerPerHour>;
using MicrometersPerHour_f = Velocity<float, MicrometerPerHour>;
using NanometersPerHour = Velocity<double, NanometerPerHour>;
using NanometersPerHour_f = Velocity<float, NanometerPerHour>;

using KilometersPerMinute = Velocity<double, KilometerPerMinute>;
using KilometersPerMinute_f = Velocity<float, KilometerPerMinute>;
using MetersPerMinute = Velocity<double, MeterPerMinute>;
using MetersPerMinute_f = Velocity<float, MeterPerMinute>;
using CentimetersPerMinute = Velocity<double, CentimeterPerMinute>;
using CentimetersPerMinute_f = Velocity<float, CentimeterPerMinute>;
using MillimetersPerMinute = Velocity<double, MillimeterPerMinute>;
using MillimetersPerMinute_f = Velocity<float, MillimeterPerMinute>;
using MicrometersPerMinute = Velocity<double, MicrometerPerMinute>;
using MicrometersPerMinute_f = Velocity<float, MicrometerPerMinute>;
using NanometersPerMinute = Velocity<double, NanometerPerMinute>;
using NanometersPerMinute_f = Velocity<float, NanometerPerMinute>;

using KilometersPerSecond = Velocity<double, KilometerPerSecond>;
using KilometersPerSecond_f = Velocity<float, KilometerPerSecond>;
using MetersPerSecond = Velocity<double, MeterPerSecond>;
using MetersPerSecond_f = Velocity<float, MeterPerSecond>;
using CentimetersPerSecond = Velocity<double, CentimeterPerSecond>;
using CentimetersPerSecond_f = Velocity<float, CentimeterPerSecond>;
using MillimetersPerSecond = Velocity<double, MillimeterPerSecond>;
using MillimetersPerSecond_f = Velocity<float, MillimeterPerSecond>;
using MicrometersPerSecond = Velocity<double, MicrometerPerSecond>;
using MicrometersPerSecond_f = Velocity<float, MicrometerPerSecond>;
using NanometersPerSecond = Velocity<double, NanometerPerSecond>;
using NanometersPerSecond_f = Velocity<float, NanometerPerSecond>;

}  // namespace Luminol::Units
