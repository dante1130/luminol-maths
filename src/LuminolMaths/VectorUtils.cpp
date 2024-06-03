#include <LuminolMaths/VectorUtils.hpp>

namespace Luminol::Maths::VectorUtils {

constexpr auto orthogonal_basis(
    Vector3& vector_a, Vector3& vector_b, Vector3& vector_c
) -> void {
    vector_a = vector_a.normalized();
    vector_c = vector_a.cross(vector_b).normalized();
    vector_b = vector_c.cross(vector_a);
}

}  // namespace Luminol::Maths::VectorUtils
