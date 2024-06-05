#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename Ratio>
using MassUnitType = UnitType<UnitEnum::Mass, Ratio>;

using Kilogram = MassUnitType<std::kilo>;
using Gram = MassUnitType<std::ratio<1>>;
using Centigram = MassUnitType<std::centi>;
using Milligram = MassUnitType<std::milli>;
using Microgram = MassUnitType<std::micro>;
using Nanogram = MassUnitType<std::nano>;

template <std::floating_point T, typename U>
using Mass = Unit<T, U>;

using Kilograms = Mass<double, Kilogram>;
using Kilograms_f = Mass<float, Kilogram>;
using Grams = Mass<double, Gram>;
using Grams_f = Mass<float, Gram>;
using Centigrams = Mass<double, Centigram>;
using Centigrams_f = Mass<float, Centigram>;
using Milligrams = Mass<double, Milligram>;
using Milligrams_f = Mass<float, Milligram>;
using Micrograms = Mass<double, Microgram>;
using Micrograms_f = Mass<float, Microgram>;
using Nanograms = Mass<double, Nanogram>;
using Nanograms_f = Mass<float, Nanogram>;

}  // namespace Luminol::Units
