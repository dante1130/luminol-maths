#pragma once

#include <LuminolMaths/Vector.hpp>

namespace Luminol::Maths::VectorUtils {

constexpr auto orthogonal_basis(
    Vector3& vector_a, Vector3& vector_b, Vector3& vector_c
) -> void;

}  // namespace Luminol::Maths::VectorUtils
