#pragma once

#include <ratio>

#include <LuminolMaths/Units/Unit.hpp>

namespace Luminol::Units {

template <typename Ratio>
using VolumeUnitType = UnitType<UnitEnum::Volume, Ratio>;

using CubicKilometer = VolumeUnitType<std::kilo>;
using CubicMeter = VolumeUnitType<std::ratio<1>>;
using CubicCentimeter = VolumeUnitType<std::centi>;
using CubicMillimeter = VolumeUnitType<std::milli>;
using CubicMicrometer = VolumeUnitType<std::micro>;
using CubicNanometer = VolumeUnitType<std::nano>;

template <std::floating_point T, typename U>
using Volume = Unit<T, U>;

using CubicKilometers = Volume<double, CubicKilometer>;
using CubicKilometers_f = Volume<float, CubicKilometer>;
using CubicMeters = Volume<double, CubicMeter>;
using CubicMeters_f = Volume<float, CubicMeter>;
using CubicCentimeters = Volume<double, CubicCentimeter>;
using CubicCentimeters_f = Volume<float, CubicCentimeter>;
using CubicMillimeters = Volume<double, CubicMillimeter>;
using CubicMillimeters_f = Volume<float, CubicMillimeter>;
using CubicMicrometers = Volume<double, CubicMicrometer>;
using CubicMicrometers_f = Volume<float, CubicMicrometer>;
using CubicNanometers = Volume<double, CubicNanometer>;
using CubicNanometers_f = Volume<float, CubicNanometer>;

}  // namespace Luminol::Units
