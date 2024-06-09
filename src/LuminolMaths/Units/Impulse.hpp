#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>
#include <LuminolMaths/Units/Mass.hpp>
#include <LuminolMaths/Units/Velocity.hpp>

namespace Luminol::Units {

template <typename Ratio>
using ImpulseUnitType = UnitType<UnitEnum::Impulse, Ratio>;

using NewtonPerSecond = ImpulseUnitType<std::ratio<1>>;

template <std::floating_point T, typename U>
using Impulse = Unit<T, U>;

template <std::floating_point T, typename MassU, typename VelocityU>
    requires(
        MassU::type == UnitEnum::Mass && VelocityU::type == UnitEnum::Velocity
    )
constexpr auto operator*(
    const Mass<T, MassU>& mass, const Velocity<T, VelocityU>& velocity
) -> Impulse<T, NewtonPerSecond> {
    const auto mass_in_kg = mass.template as<Kilogram>().get_value();
    const auto velocity_in_mps =
        velocity.template as<MeterPerSecond>().get_value();

    const auto newtons_per_second = mass_in_kg * velocity_in_mps;

    return Impulse<T, NewtonPerSecond>{newtons_per_second};
}

using NewtonPerSeconds = Impulse<double, NewtonPerSecond>;
using NewtonPerSeconds_f = Impulse<float, NewtonPerSecond>;

}  // namespace Luminol::Units
