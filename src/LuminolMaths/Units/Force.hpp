#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>
#include <LuminolMaths/Units/Mass.hpp>
#include <LuminolMaths/Units/Acceleration.hpp>

namespace Luminol::Units {

template <typename Ratio>
using ForceUnitType = UnitType<UnitEnum::Force, Ratio>;

using Newton = ForceUnitType<std::ratio<1>>;

template <std::floating_point T, typename U>
using Force = Unit<T, U>;

template <std::floating_point T, typename MassU, typename AccelerationU>
    requires(
        MassU::type == UnitEnum::Mass &&
        AccelerationU::type == UnitEnum::Acceleration
    )
constexpr auto operator*(
    const Mass<T, MassU>& mass,
    const Acceleration<T, AccelerationU>& acceleration
) -> Force<T, Newton> {
    const auto mass_in_kg = mass.template as<Kilogram>().get_value();
    const auto acceleration_in_mps2 =
        acceleration.template as<MeterPerSecondSquared>().get_value();

    const auto newtons = mass_in_kg * acceleration_in_mps2;

    return Force<T, Newton>{newtons};
}

using Newtons = Force<double, Newton>;
using Newtons_f = Force<float, Newton>;

}  // namespace Luminol::Units
