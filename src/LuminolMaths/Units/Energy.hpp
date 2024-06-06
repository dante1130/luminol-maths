#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>
#include <LuminolMaths/Units/Mass.hpp>
#include <LuminolMaths/Units/Velocity.hpp>

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
    template <typename MassU, typename VelocityU>
        requires(
            MassU::type == UnitEnum::Mass &&
            VelocityU::type == UnitEnum::Velocity
        )
    constexpr Energy(
        const Mass<T, MassU>& mass, const Velocity<T, VelocityU>& velocity
    )
        : Unit<T, U>{energy_from_mass_and_velocity(mass, velocity)} {}

private:
    template <typename MassU, typename VelocityU>
        requires(
            MassU::type == UnitEnum::Mass &&
            VelocityU::type == UnitEnum::Velocity
        )
    constexpr static auto energy_from_mass_and_velocity(
        const Mass<T, MassU>& mass, const Velocity<T, VelocityU>& velocity
    ) -> T {
        const auto mass_in_kg = mass.template as<Kilogram>().get_value();
        const auto velocity_in_mps =
            velocity.template as<MeterPerSecond>().get_value();

        constexpr auto half = T{0.5};
        const auto joules =
            half * mass_in_kg * velocity_in_mps * velocity_in_mps;

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
