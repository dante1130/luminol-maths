#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>

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
using Energy = Unit<T, U>;

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
