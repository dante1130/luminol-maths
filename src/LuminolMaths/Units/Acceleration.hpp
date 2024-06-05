#pragma once

#include <ratio>

#include <LuminolMaths/Units/Speed.hpp>
#include <LuminolMaths/Units/Time.hpp>
#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename SpeedU, typename TimeU>
    requires(SpeedU::type == UnitEnum::Speed && TimeU::type == UnitEnum::Time)
class AccelerationUnitType
    : public UnitType<
          UnitEnum::Acceleration,
          std::ratio_divide<typename SpeedU::ratio, typename TimeU::ratio>> {
public:
    using SpeedType = SpeedU;
};

using KilometerPerHourSquared = AccelerationUnitType<KilometerPerHour, Hour>;
using MeterPerHourSquared = AccelerationUnitType<MeterPerHour, Hour>;
using CentimeterPerHourSquared = AccelerationUnitType<CentimeterPerHour, Hour>;
using MillimeterPerHourSquared = AccelerationUnitType<MillimeterPerHour, Hour>;
using MicrometerPerHourSquared = AccelerationUnitType<MicrometerPerHour, Hour>;
using NanometerPerHourSquared = AccelerationUnitType<NanometerPerHour, Hour>;

using KilometerPerMinuteSquared =
    AccelerationUnitType<KilometerPerMinute, Minute>;
using MeterPerMinuteSquared = AccelerationUnitType<MeterPerMinute, Minute>;
using CentimeterPerMinuteSquared =
    AccelerationUnitType<CentimeterPerMinute, Minute>;
using MillimeterPerMinuteSquared =
    AccelerationUnitType<MillimeterPerMinute, Minute>;
using MicrometerPerMinuteSquared =
    AccelerationUnitType<MicrometerPerMinute, Minute>;
using NanometerPerMinuteSquared =
    AccelerationUnitType<NanometerPerMinute, Minute>;

using KilometerPerSecondSquared =
    AccelerationUnitType<KilometerPerSecond, Second>;
using MeterPerSecondSquared = AccelerationUnitType<MeterPerSecond, Second>;
using CentimeterPerSecondSquared =
    AccelerationUnitType<CentimeterPerSecond, Second>;
using MillimeterPerSecondSquared =
    AccelerationUnitType<MillimeterPerSecond, Second>;
using MicrometerPerSecondSquared =
    AccelerationUnitType<MicrometerPerSecond, Second>;
using NanometerPerSecondSquared =
    AccelerationUnitType<NanometerPerSecond, Second>;

template <std::floating_point T, typename U>
class Acceleration : public Unit<T, U> {
public:
    template <typename TimeU>
        requires(TimeU::type == UnitEnum::Time)
    constexpr auto operator*(const Time<T, TimeU>& time) const
        -> Speed<T, typename U::SpeedType> {
        return Speed<T, typename U::SpeedType>{
            this->get_value() * time.get_value() *
            time.template get_ratio<typename U::SpeedType>()
        };
    }
};

template <std::floating_point T, typename SpeedU, typename TimeU>
    requires(SpeedU::type == UnitEnum::Speed && TimeU::type == UnitEnum::Time)
constexpr auto operator/(
    const Speed<T, SpeedU>& velocity, const Time<T, TimeU>& time
) -> Acceleration<T, AccelerationUnitType<SpeedU, TimeU>> {
    return Acceleration<T, AccelerationUnitType<SpeedU, TimeU>>{
        velocity.get_value() / time.get_value() *
        velocity.template get_ratio<TimeU>()
    };
}

using KilometersPerHourSquared = Acceleration<double, KilometerPerHourSquared>;
using KilometersPerHourSquared_f = Acceleration<float, KilometerPerHourSquared>;
using MetersPerHourSquared = Acceleration<double, MeterPerHourSquared>;
using MetersPerHourSquared_f = Acceleration<float, MeterPerHourSquared>;
using CentimetersPerHourSquared =
    Acceleration<double, CentimeterPerHourSquared>;
using CentimetersPerHourSquared_f =
    Acceleration<float, CentimeterPerHourSquared>;
using MillimetersPerHourSquared =
    Acceleration<double, MillimeterPerHourSquared>;
using MillimetersPerHourSquared_f =
    Acceleration<float, MillimeterPerHourSquared>;
using MicrometersPerHourSquared =
    Acceleration<double, MicrometerPerHourSquared>;
using MicrometersPerHourSquared_f =
    Acceleration<float, MicrometerPerHourSquared>;
using NanometersPerHourSquared = Acceleration<double, NanometerPerHourSquared>;
using NanometersPerHourSquared_f = Acceleration<float, NanometerPerHourSquared>;

using KilometersPerMinuteSquared =
    Acceleration<double, KilometerPerMinuteSquared>;
using KilometersPerMinuteSquared_f =
    Acceleration<float, KilometerPerMinuteSquared>;
using MetersPerMinuteSquared = Acceleration<double, MeterPerMinuteSquared>;
using MetersPerMinuteSquared_f = Acceleration<float, MeterPerMinuteSquared>;
using CentimetersPerMinuteSquared =
    Acceleration<double, CentimeterPerMinuteSquared>;
using CentimetersPerMinuteSquared_f =
    Acceleration<float, CentimeterPerMinuteSquared>;
using MillimetersPerMinuteSquared =
    Acceleration<double, MillimeterPerMinuteSquared>;
using MillimetersPerMinuteSquared_f =
    Acceleration<float, MillimeterPerMinuteSquared>;
using MicrometersPerMinuteSquared =
    Acceleration<double, MicrometerPerMinuteSquared>;
using MicrometersPerMinuteSquared_f =
    Acceleration<float, MicrometerPerMinuteSquared>;
using NanometersPerMinuteSquared =
    Acceleration<double, NanometerPerMinuteSquared>;
using NanometersPerMinuteSquared_f =
    Acceleration<float, NanometerPerMinuteSquared>;

using KilometersPerSecondSquared =
    Acceleration<double, KilometerPerSecondSquared>;
using KilometersPerSecondSquared_f =
    Acceleration<float, KilometerPerSecondSquared>;
using MetersPerSecondSquared = Acceleration<double, MeterPerSecondSquared>;
using MetersPerSecondSquared_f = Acceleration<float, MeterPerSecondSquared>;
using CentimetersPerSecondSquared =
    Acceleration<double, CentimeterPerSecondSquared>;
using CentimetersPerSecondSquared_f =
    Acceleration<float, CentimeterPerSecondSquared>;
using MillimetersPerSecondSquared =
    Acceleration<double, MillimeterPerSecondSquared>;
using MillimetersPerSecondSquared_f =
    Acceleration<float, MillimeterPerSecondSquared>;
using MicrometersPerSecondSquared =
    Acceleration<double, MicrometerPerSecondSquared>;
using MicrometersPerSecondSquared_f =
    Acceleration<float, MicrometerPerSecondSquared>;
using NanometersPerSecondSquared =
    Acceleration<double, NanometerPerSecondSquared>;
using NanometersPerSecondSquared_f =
    Acceleration<float, NanometerPerSecondSquared>;

}  // namespace Luminol::Units
