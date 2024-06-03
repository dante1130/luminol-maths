#include <LuminolMaths/VectorUtils.hpp>

namespace Luminol::Maths::VectorUtils {

constexpr auto orthogonal_basis(
    const Vector3& vector_a, const Vector3& vector_b
) -> std::tuple<Vector3, Vector3, Vector3> {
    const auto vector_a_normalized = vector_a.normalized();

    auto vector_c = vector_a_normalized.cross(vector_b);

    if (vector_c.length() == 0.0) {
        return {vector_a_normalized, vector_b, vector_c};
    }

    vector_c = vector_c.normalized();

    const auto vector_b_orthogonal = vector_c.cross(vector_a_normalized);

    return {vector_a_normalized, vector_b_orthogonal, vector_c};
}

}  // namespace Luminol::Maths::VectorUtils
