#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>
#include <LuminolMaths/Units/Mass.hpp>
#include <LuminolMaths/Units/Volume.hpp>

namespace Luminol::Units {

template <typename Ratio>
using DensityUnitType = UnitType<UnitEnum::Density, Ratio>;

using KilogramPerCubicMeter = DensityUnitType<std::ratio<1>>;

template <std::floating_point T, typename U>
using Density = Unit<T, U>;

template <std::floating_point T, typename MassU, typename VolumeU>
    requires(MassU::type == UnitEnum::Mass && VolumeU::type == UnitEnum::Volume)
constexpr auto operator/(
    const Mass<T, MassU>& mass, const Volume<T, VolumeU>& volume
) -> Density<T, KilogramPerCubicMeter> {
    const auto mass_in_kg = mass.template as<Kilogram>().get_value();
    const auto volume_in_m3 = volume.template as<CubicMeter>().get_value();

    const auto density = mass_in_kg / volume_in_m3;

    return Density<T, KilogramPerCubicMeter>{density};
}

using KilogramsPerCubicMeter = Density<double, KilogramPerCubicMeter>;
using KilogramsPerCubicMeter_f = Density<float, KilogramPerCubicMeter>;

}  // namespace Luminol::Units
