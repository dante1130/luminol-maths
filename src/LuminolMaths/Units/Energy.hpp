#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>
#include <LuminolMaths/Units/Mass.hpp>
#include <LuminolMaths/Units/Speed.hpp>

namespace Luminol::Units {

template <typename Ratio>
using EnergyUnitType = UnitType<UnitEnum::Energy, Ratio>;

using Kilojoule = EnergyUnitType<std::kilo>;
using Joule = EnergyUnitType<std::ratio<1>>;
using Centijoule = EnergyUnitType<std::centi>;
using Millijoule = EnergyUnitType<std::milli>;
using Microjoule = EnergyUnitType<std::micro>;
using Nanojoule = EnergyUnitType<std::nano>;

template <std::floating_point T, typename U>
class Energy : public Unit<T, U> {
public:
    template <typename MassU, typename SpeedU>
        requires(
            MassU::type == UnitEnum::Mass && SpeedU::type == UnitEnum::Speed
        )
    constexpr Energy(const Mass<T, MassU>& mass, const Speed<T, SpeedU>& speed)
        : Unit<T, U>{energy_from_mass_and_speed(mass, speed)} {}

private:
    template <typename MassU, typename SpeedU>
        requires(
            MassU::type == UnitEnum::Mass && SpeedU::type == UnitEnum::Speed
        )
    constexpr static auto energy_from_mass_and_speed(
        const Mass<T, MassU>& mass, const Speed<T, SpeedU>& speed
    ) -> T {
        const auto mass_in_kg = mass.template as<Kilogram>().get_value();
        const auto speed_in_mps =
            speed.template as<MeterPerSecond>().get_value();

        constexpr auto half = T{0.5};
        const auto joules = half * mass_in_kg * speed_in_mps * speed_in_mps;

        constexpr auto energy_ratio = U::ratio::num / U::ratio::den;

        return joules * (T{1.0} / energy_ratio);
    }
};

using Kilojoules = Energy<double, Kilojoule>;
using Kilojoules_f = Energy<float, Kilojoule>;
using Joules = Energy<double, Joule>;
using Joules_f = Energy<float, Joule>;
using Centijoules = Energy<double, Centijoule>;
using Centijoules_f = Energy<float, Centijoule>;
using Millijoules = Energy<double, Millijoule>;
using Millijoules_f = Energy<float, Millijoule>;
using Microjoules = Energy<double, Microjoule>;
using Microjoules_f = Energy<float, Microjoule>;
using Nanojoules = Energy<double, Nanojoule>;
using Nanojoules_f = Energy<float, Nanojoule>;

}  // namespace Luminol::Units
