#pragma once

#include <LuminolMaths/Vector.hpp>

namespace Luminol::Maths::VectorUtils {

constexpr auto orthogonal_basis(
    const Vector3& vector_a, const Vector3& vector_b
) -> std::tuple<Vector3, Vector3, Vector3>;

}  // namespace Luminol::Maths::VectorUtils
